QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualWaitingSpinner
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11

SOURCES += \
        ../waitingspinnerwidget.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        ../waitingspinnerwidget.h \
        mainwindow.h

FORMS += \
        mainwindow.ui



