#-------------------------------------------------
#
# Project created by QtCreator 2017-09-08T18:01:50
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniStocks
TEMPLATE = app

# check if compiling computer has libcurl library
# else CSV files containing stock data will be downloaded
# using Qt functions
packagesExist(curl) {
    DEFINES += HAS_CURL:
    LIBS += -lcurl
}


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    File.cpp \
    TickerInfoDownloader.cpp \
    dialogs/About.cpp \
    dialogs/MainWindow.cpp \
    dialogs/SettingsDialog.cpp \
    file/File.cpp \
        main.cpp \
    Ticker.cpp \
    TickerItem.cpp \
    About.cpp \
    SettingsDialog.cpp \
    MainWindow.cpp \
    TickerRefreshThread.cpp \
    ticker/Ticker.cpp \
    ticker/TickerInfoDownloader.cpp \
    ticker/TickerItem.cpp \
    ticker/TickerRefreshThread.cpp



HEADERS += \
    File.h \
    Ticker.h \
    TickerInfoDownloader.h \
    TickerItem.h \
    SettingsDialog.h \
    About.h \
    MainWindow.h \
    TickerRefreshThread.h \
    dialogs/About.h \
    dialogs/MainWindow.h \
    dialogs/SettingsDialog.h \
    file/File.h \
    ticker/Ticker.h \
    ticker/TickerInfoDownloader.h \
    ticker/TickerItem.h \
    ticker/TickerRefreshThread.h



FORMS += \
    dialogs/about.ui \
    dialogs/mainwindow.ui \
    dialogs/settingsdialog.ui \
    settingsdialog.ui \
    about.ui \
    mainwindow.ui

