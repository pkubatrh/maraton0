#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T21:59:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PernikovaChaloupka
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clickablelabel.cpp \
    detskeokenko.cpp

HEADERS  += mainwindow.h \
    clickablelabel.h \
    detskeokenko.h

FORMS    += mainwindow.ui \
    detskeokenko.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc
