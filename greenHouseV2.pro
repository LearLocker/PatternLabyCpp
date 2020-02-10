#-------------------------------------------------
#
# Project created by QtCreator 2020-01-20T10:14:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = greenHouseV2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    state.cpp \
    logger.cpp \
    loggerimpl.cpp

HEADERS += \
        mainwindow.h \
    plant.h \
    plantfactory.h \
    greenhouse.h \
    sensor.h \
    command.h \
    light.h \
    state.h \
    logger.h \
    loggerimpl.h \
    proxygreenhouse.h \
    igreenhouse.h \
    decorator.h \
    facade.h \
    cooler.h

FORMS += \
        mainwindow.ui
