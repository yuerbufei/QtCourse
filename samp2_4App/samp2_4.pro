#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T00:17:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = samp2_4
TEMPLATE = app


SOURCES += main.cpp\
        aboutdialog.cpp \
        qwmainwind.cpp

HEADERS  += qwmainwind.h \
    aboutdialog.h

FORMS    += qwmainwind.ui \
    aboutdialog.ui

RESOURCES += \
    res.qrc

RC_ICONS = AppIcon.ico
