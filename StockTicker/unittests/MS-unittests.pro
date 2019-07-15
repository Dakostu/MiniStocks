# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = MS-unittests

QT += core gui
QT += network
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = unittests
INCLUDEPATH += .

HEADERS = \
   $$PWD/TickerItemUnitTest.h \
   $$PWD/../file/File.h \
   $$PWD/../ticker/TickerInfoDownloader.h \
   $$PWD/../ticker/TickerItem.h \
   TickerUnitTest.h

SOURCES = \
   $$PWD/TickerItemUnitTest.cpp \
   $$PWD/../file/File.cpp \
   $$PWD/unittestmain.cpp \
   $$PWD/../ticker/TickerInfoDownloader.cpp \
   $$PWD/../ticker/TickerItem.cpp \
   TickerUnitTest.cpp

INCLUDEPATH = \
    $$PWD/.

#DEFINES =

