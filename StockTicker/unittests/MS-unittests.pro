# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = MS-unittests

QT += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = unittests
INCLUDEPATH += .

HEADERS = \
   $$PWD/TickerItemUnitTest.h

SOURCES = \
   $$PWD/TickerItemUnitTest.cpp \
   $$PWD/unittestmain.cpp \
   $$PWD/unittests.pro

INCLUDEPATH = \
    $$PWD/.

#DEFINES =

