#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T21:59:06
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PernikovaChaloupka
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clickablelabel.cpp \
    detskeokenko.cpp \
    ditevideo.cpp \
    jezibaba.cpp \
    chat.cpp

HEADERS  += mainwindow.h \
    clickablelabel.h \
    detskeokenko.h \
    ditevideo.h \
    jezibaba.h \
    chat.h

FORMS    += mainwindow.ui \
    detskeokenko.ui \
    ditevideo.ui \
    jezibaba.ui \
    chat.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc \
    sounds.qrc
