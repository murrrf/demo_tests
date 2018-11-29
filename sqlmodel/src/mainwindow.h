#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file
 * @~english
 * @brief
 * 
 * @~russian
 * @brief
 */

#include <QMainWindow>
#include <QSqlDatabase>

// Forward declarations
class TableWidget;

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param parent
     */
    MainWindow(QWidget *parent = 0);
    /**
     * @brief
     */
    ~MainWindow();
private:
    /**
     * @brief barMainMenu
     */
    QMenuBar *barMainMenu;
    /**
     * @brief menuFile
     */
    QMenu *menuFile;
    /**
     * @brief menuTools
     */
    QMenu *menuTools;
    /**
     * @brief menuHelp
     */
    QMenu *menuHelp;
    /**
     * @brief barTools
     */
    QToolBar *barTools;
    /**
     * @brief barStatus
     */
    QStatusBar *barStatus;
    /**
     * @brief actnFileExit
     */
    QAction *actnFileExit;
    /**
     * @brief actnToolsConnect
     */
    QAction *actnToolsConnect;
    /**
     * @brief actnHelpAbout
     */
    QAction *actnHelpAbout;
    /**
     * @brief actnHelpAboutQt
     */
    QAction *actnHelpAboutQt;
    /**
     * @brief db
     */
    QSqlDatabase db;
    /**
     * @brief hostname
     */
    QString hostname;
    /**
     * @brief username
     */
    QString username;
    /**
     * @brief userpass
     */
    QString userpass;
    /**
     * @brief dbname
     */
    QString dbname;
    /**
     * @brief tablename
     */
    QString tablename;
    /**
     * @brief tblMain
     */
    TableWidget *tblMain;
private slots:
    /**
     * @brief onFileExit
     */
    void onFileExit();
    /**
     * @brief onToolsConnect
     */
    void onToolsConnect();
    /**
     * @~english
     * @brief About action handler.
     *
     * @~russian
     * @brief Обработчик действия «О программе».
     */
    void onHelpAbout();
    /**
     * @~english
     * @brief About Qt action handler.
     *
     * @~russian
     * @brief Обработчик действия «О Qt».
     */
    void onHelpAboutQt();
};

#endif // MAINWINDOW_H
