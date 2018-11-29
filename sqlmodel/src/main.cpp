#include "mainwindow.h"
#include <QApplication>

/*
 * @file
 * @~english
 * @brief Main application source file.
 *
 * @~russian
 * @brief Главный исходный файл приложения.
 */

/*
 * @~english
 * @brief Application entry point.
 * @param argc Number of command-line arguments.
 * @param argv List of command-line arguments.
 * @return Return code.
 *
 * @~russian
 * @brief Точка входа приложения.
 * @param argc Число аргументов командной строки.
 * @param argv Список аргументов командной строки.
 * @return Код возврата.
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("SQL Model Test");
    app.setApplicationVersion(VERSIONSTR);
    app.setOrganizationDomain("demo_tests");
    app.setOrganizationName("demo_tests");
    MainWindow w;
    w.show();

    return app.exec();
}
