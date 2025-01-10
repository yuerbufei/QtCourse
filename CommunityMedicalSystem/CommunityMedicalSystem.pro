QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databaseconnection.cpp \
    # departmentview.cpp \
    doctorview.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    medicaleditview.cpp \
    medicalview.cpp \
    patienteditview.cpp \
    patientview.cpp \
    recordeditview.cpp \
    recordview.cpp \
    welcomeview.cpp

HEADERS += \
    databaseconnection.h \
    # departmentview.h \
    doctorview.h \
    loginview.h \
    masterview.h \
    medicaleditview.h \
    medicalview.h \
    patienteditview.h \
    patientview.h \
    recordeditview.h \
    recordview.h \
    welcomeview.h

FORMS += \
    # departmentview.ui \
    doctorview.ui \
    loginview.ui \
    masterview.ui \
    medicaleditview.ui \
    medicalview.ui \
    patienteditview.ui \
    patientview.ui \
    recordeditview.ui \
    recordview.ui \
    welcomeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
