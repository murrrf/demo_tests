#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

/**
 * @file
 * @~english
 * @brief The module of connection settings dialog window.
 * 
 * @~russian
 * @brief Модуль диалогового окна настроек подключения.
 */

#include <QDialog>

//Forward declarations
class QVBoxLayout;
class QGridLayout;
class QLabel;
class QLineEdit;
class QDialogButtonBox;

/**
 * @~english
 * @brief The class of connection settings dialog window.
 *
 * @~russian
 * @brief Класс диалогового окна настроек подключения.
 */
class ConnectDialog : public QDialog
{
    Q_OBJECT
public:
    /**
     * @~english
     * @brief Constructor of the class.
     * @param parent Pointer to parent window.
     *
     * @~russian
     * @brief Конструктор класса.
     * @param parent Указатель на родительское окно.
     */
    explicit ConnectDialog(QWidget *parent = 0);
    /**
     * @~english
     * @brief Destructor of the class.
     *
     * @~russian
     * @brief Деструктор класса.
     */
    ~ConnectDialog();
    /**
     * @~english
     * @brief
     * @param hostaddress
     *
     * @~russian
     * @brief
     * @param hostaddress
     */
    void setHostAddress(const QString &hostaddress);
    /**
     * @~english
     * @brief
     * @return
     *
     * @~russian
     * @brief
     * @return
     */
    QString getHostAddress();
    /**
     * @~english
     * @brief
     * @param hostaddress
     *
     * @~russian
     * @brief
     * @param hostaddress
     */
    void setUserName(const QString &username);
    /**
     * @~english
     * @brief
     * @return
     *
     * @~russian
     * @brief
     * @return
     */
    QString getUserName();
    /**
     * @~english
     * @brief
     * @param hostaddress
     *
     * @~russian
     * @brief
     * @param hostaddress
     */
    void setUserPassword(const QString &userpassword);
    /**
     * @~english
     * @brief
     * @return
     *
     * @~russian
     * @brief
     * @return
     */
    QString getUserPassword();
    /**
     * @~english
     * @brief
     * @param hostaddress
     *
     * @~russian
     * @brief
     * @param hostaddress
     */
    void setDatabaseName(const QString &databasename);
    /**
     * @~english
     * @brief
     * @return
     *
     * @~russian
     * @brief
     * @return
     */
    QString getDatabaseName();
    /**
     * @~english
     * @brief
     * @param hostaddress
     *
     * @~russian
     * @brief
     * @param hostaddress
     */
    void setTableName(const QString &tablename);
    /**
     * @~english
     * @brief
     * @return
     *
     * @~russian
     * @brief
     * @return
     */
    QString getTableName();

signals:

public slots:
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    void accept();
private:
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QVBoxLayout *boxMain;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QGridLayout *boxSettings;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLabel *lblHostAddress;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLineEdit *edtHostAddress;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLabel *lblUserName;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLineEdit *edtUserName;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLabel *lblUserPassword;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLineEdit *edtUserPassword;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLabel *lblDatabaseName;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLineEdit *edtDatabaseName;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLabel *lblTableName;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QLineEdit *edtTableName;
    /**
     * @~english
     * @brief
     *
     * @~russian
     * @brief
     */
    QDialogButtonBox *boxButtons;
};

#endif // CONNECTDIALOG_H
