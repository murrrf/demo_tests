#ifndef CONSTS_H
#define CONSTS_H

/**
 * @file
 * @~english
 * @brief File of common constants.
 *
 * @~russian
 * @brief Файл общих констант программы.
 */

/**
 * @~english
 * @brief The namespace of string constants.
 *
 * @~russian
 * @brief Пространство имен строковых констант.
 */
namespace CONSTS
{
/**
 * @~english
 * @brief The name of developer.
 *
 * @~russian
 * @brief Наименование разработчика.
 */
const QString devel = "demo_tests";
/**
 * @~english
 * @brief The name of application.
 *
 * @~russian
 * @brief Наименование приложения.
 */
const QString program = "SQLModelTest";
/**
 * @~english
 * @brief Address of host machine.
 *
 * @~russian
 * @brief Адрес хоста, на котором располагается СУБД.
 */
const QString hostname = "Host name";
/**
 * @~english
 * @brief User login.
 *
 * @~russian
 * @brief Логин пользователя СУБД.
 */
const QString username = "User name";
/**
 * @~english
 * @brief User password.
 *
 * @~russian
 * @brief Пароль пользователя СУБД.
 */
const QString userpass = "User password";
/**
 * @~english
 * @brief Name of database.
 *
 * @~russian
 * @brief Название базы данных.
 */
const QString dbname = "Database name";
/**
 * @~english
 * @brief Name of database table.
 *
 * @~russian
 * @brief Название таблицы в базе данных.
 */
const QString tablename = "Table name";
}

/**
 * @~english
 * @brief Maximum string length in the input field.
 *
 * @~russian
 * @brief Максимальная длина строки в поле ввода.
 */
const int maxTextLength = 100;
#endif // CONSTS_H
