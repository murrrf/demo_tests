#include "mainwindow.h"

#include "connectdialog.h"
#include "tablewidget.h"
#include "consts.h"

#include <QWidget>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QSettings>
#include <QMessageBox>
#include <QApplication>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1024, 768);

    barMainMenu = new QMenuBar();

    menuFile = new QMenu(tr("File"));
    menuTools = new QMenu(tr("Tools"));
    menuHelp = new QMenu(tr("Help"));

    barMainMenu->addMenu(menuFile);
    barMainMenu->addMenu(menuTools);
    barMainMenu->addMenu(menuHelp);
    barMainMenu->show();
    barMainMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    barTools = new QToolBar();
    barTools->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    barStatus = new QStatusBar();
    barStatus->setSizeGripEnabled(true);

    this->setMenuBar(barMainMenu);
    this->addToolBar(barTools);
    this->setStatusBar(barStatus);

    actnFileExit = new QAction(QIcon::fromTheme("application-exit"), tr("Exit"), this);
    connect(actnFileExit, SIGNAL(triggered()), this, SLOT(onFileExit()));
    menuFile->addAction(actnFileExit);

    actnToolsConnect = new QAction(QIcon::fromTheme("network-wired"), tr("Connect..."), this);
    connect(actnToolsConnect, SIGNAL(triggered()), this, SLOT(onToolsConnect()));
    menuTools->addAction(actnToolsConnect);
    barTools->addAction(actnToolsConnect);

    actnHelpAbout = new QAction(QIcon::fromTheme("help-about"), tr("About..."), this);
    connect(actnHelpAbout, SIGNAL(triggered()), this, SLOT(onHelpAbout()));
    menuHelp->addAction(actnHelpAbout);

    actnHelpAboutQt = new QAction(
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
        QIcon(":/qt-project.org/qmessagebox/images/qtlogo-64.png"),
#else
        QIcon(":/trolltech/qmessagebox/images/qtlogo-64.png"),
#endif
        tr("About Qt..."), this);
    connect(actnHelpAboutQt, SIGNAL(triggered()), this, SLOT(onHelpAboutQt()));
    menuHelp->addAction(actnHelpAboutQt);

    QSettings settings(CONSTS::devel, CONSTS::program);
    hostname = settings.value(CONSTS::hostname, "127.0.0.1").toString();
    username = settings.value(CONSTS::username, "user").toString();
    userpass = settings.value(CONSTS::userpass, "password").toString();
    dbname = settings.value(CONSTS::dbname, "testdb").toString();
    tablename = settings.value(CONSTS::tablename, "test").toString();

    db = QSqlDatabase::addDatabase("QPSQL");

    tblMain = new TableWidget(db);
    this->setCentralWidget(tblMain);
}

MainWindow::~MainWindow()
{
    if (db.isOpen())
    {
        db.close();
    }

    delete tblMain;
    delete actnHelpAbout;
    delete actnToolsConnect;
    delete actnFileExit;
    delete barStatus;
    delete barTools;
    delete menuHelp;
    delete menuTools;
    delete menuFile;
    delete barMainMenu;
}

void MainWindow::onFileExit()
{
    close();
}

void MainWindow::onToolsConnect()
{
    ConnectDialog *dlgConnect = new ConnectDialog();
    dlgConnect->setHostAddress(hostname);
    dlgConnect->setUserName(username);
    dlgConnect->setUserPassword(userpass);
    dlgConnect->setDatabaseName(dbname);
    dlgConnect->setTableName(tablename);

    if (dlgConnect->exec() == QDialog::Accepted)
    {
        hostname = dlgConnect->getHostAddress();
        username = dlgConnect->getUserName();
        userpass = dlgConnect->getUserPassword();
        dbname = dlgConnect->getDatabaseName();
        tablename = dlgConnect->getTableName();

        QSettings settings(CONSTS::devel, CONSTS::program);
        settings.setValue(CONSTS::hostname, hostname);
        settings.setValue(CONSTS::username, username);
        settings.setValue(CONSTS::userpass, userpass);
        settings.setValue(CONSTS::dbname, dbname);
        settings.setValue(CONSTS::tablename, tablename);

        if (db.isOpen())
        {
            db.close();
        }

        db.setHostName(hostname);
        db.setDatabaseName(dbname);
        db.setUserName(username);
        db.setPassword(userpass);

        if (!db.open())
        {
            QMessageBox:: critical(this, tr("Error"), tr("Cannot connect to database:\n") + db.lastError().text());
        }
        else
        {
            tblMain->setTable(tablename);
        }
    }

    delete dlgConnect;
}

void MainWindow::onHelpAbout()
{
    QString caption = tr("About SQL Model Test");
    QString message = tr("<p>") + tr("A simple example demonstrating") + tr("<br>") +
                      tr("how to work with QSQLTableModel") + tr("</p>") +
                      tr("<p>Version: %1</p>").arg(QApplication::applicationVersion());
    QMessageBox::about(this, caption, message);
}

void MainWindow::onHelpAboutQt()
{
    QMessageBox::aboutQt(this);
}
