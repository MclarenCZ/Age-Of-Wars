#-------------------------------------------------
#
# Project created by QtCreator 2017-05-26T08:55:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Age_Of_Wars
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    player.cpp \
    base.cpp \
    turret.cpp \
    bullet.cpp

HEADERS  += mainwindow.h \
    view.h \
    player.h \
    base.h \
    turret.h \
    bullet.h

FORMS    += mainwindow.ui
