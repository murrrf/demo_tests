#include "connectdialog.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle(tr("Connection parameters"));

    boxSettings = new QGridLayout();

    lblHostAddress = new QLabel(tr("Host address"));
    boxSettings->addWidget(lblHostAddress, 0, 0);

    edtHostAddress = new QLineEdit();
    boxSettings->addWidget(edtHostAddress, 0, 1);

    lblUserName = new QLabel(tr("User name"));
    boxSettings->addWidget(lblUserName, 1, 0);

    edtUserName = new QLineEdit();
    boxSettings->addWidget(edtUserName, 1, 1);

    lblUserPassword = new QLabel(tr("User password"));
    boxSettings->addWidget(lblUserPassword, 2, 0);

    edtUserPassword = new QLineEdit();
    edtUserPassword->setEchoMode(QLineEdit::Password);
    boxSettings->addWidget(edtUserPassword, 2, 1);

    lblDatabaseName = new QLabel(tr("Database name"));
    boxSettings->addWidget(lblDatabaseName, 4, 0);

    edtDatabaseName = new QLineEdit();
    boxSettings->addWidget(edtDatabaseName, 4, 1);

    lblTableName = new QLabel(tr("Table name"));
    boxSettings->addWidget(lblTableName, 5, 0);

    edtTableName = new QLineEdit();
    boxSettings->addWidget(edtTableName, 5, 1);

    boxButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(boxButtons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(boxButtons, SIGNAL(rejected()), this, SLOT(reject()));

    boxMain = new QVBoxLayout();
    boxMain->addLayout(boxSettings);
    boxMain->addWidget(boxButtons);
    this->setLayout(boxMain);
}

ConnectDialog::~ConnectDialog()
{
    delete lblHostAddress;
    delete edtHostAddress;
    delete lblUserName;
    delete edtUserName;
    delete lblUserPassword;
    delete edtUserPassword;
    delete lblTableName;
    delete edtTableName;
    delete lblDatabaseName;
    delete edtDatabaseName;
    delete boxSettings;
    delete boxButtons;
    delete boxMain;
}

void ConnectDialog::setHostAddress(const QString &hostaddress)
{
    edtHostAddress->setText(hostaddress);
}

QString ConnectDialog::getHostAddress()
{
    return edtHostAddress->text();
}

void ConnectDialog::setUserName(const QString &username)
{
    edtUserName->setText(username);
}

QString ConnectDialog::getUserName()
{
    return edtUserName->text();
}

void ConnectDialog::setUserPassword(const QString &userpassword)
{
    edtUserPassword->setText(userpassword);
}

QString ConnectDialog::getUserPassword()
{
    return edtUserPassword->text();
}

void ConnectDialog::setDatabaseName(const QString &databasename)
{
    edtDatabaseName->setText(databasename);
}

QString ConnectDialog::getDatabaseName()
{
    return edtDatabaseName->text();
}

void ConnectDialog::setTableName(const QString &tablename)
{
    edtTableName->setText(tablename);
}

QString ConnectDialog::getTableName()
{
    return edtTableName->text();
}

void ConnectDialog::accept()
{
    QDialog::accept();
}
