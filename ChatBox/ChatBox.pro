#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T14:30:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatBox
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chat.cpp

HEADERS  += mainwindow.h \
    chat.h

FORMS    += mainwindow.ui \
    chat.ui
