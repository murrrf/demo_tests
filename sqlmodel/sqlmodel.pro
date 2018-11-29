#-------------------------------------------------
#
# Project created by QtCreator 2018-11-07T19:56:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlmodel
TEMPLATE = app
VERSION = 0.0.1
DEFINES += VERSIONSTR=\\\"$${VERSION}\\\"

SOURCES += \
    src/main.cpp\
    src/mainwindow.cpp \
    src/tablewidget.cpp \
    src/connectdialog.cpp \
    src/recordeditor.cpp

HEADERS += \
    src/mainwindow.h \
    src/tablewidget.h \
    src/connectdialog.h \
    src/recordeditor.h \
    src/consts.h
