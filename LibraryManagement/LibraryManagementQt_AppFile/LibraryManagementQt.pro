#-------------------------------------------------
#
# Project created by QtCreator 2025-08-14T05:14:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManagementQt
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    LibraryItem.cpp \
    Book.cpp \
    Magazine.cpp

HEADERS  += mainwindow.h \
    LibraryItem.h \
    Book.h \
    Magazine.h

FORMS    += mainwindow.ui
