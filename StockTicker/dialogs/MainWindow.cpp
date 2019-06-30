/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the Main window
 * (black window that shows all tickers and prices)
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "TickerRefreshThread.h"
#include "Ticker.h"
#include "SettingsDialog.h"
#include "About.h"
#include <QApplication>
#include <QLabel>
#include <QMenu>
#include <QObject>
#include <QShortcut>
#include <thread>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint, true);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    this->setAttribute(Qt::WA_QuitOnClose,true);

    currentFont = ui->symbolColumn->font().toString();

    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(endProgram()));
    new QShortcut(QKeySequence(Qt::Key_A), this, SLOT(openAbout()));
    new QShortcut(QKeySequence(Qt::Key_S), this, SLOT(openSettings()));
    new QShortcut(QKeySequence(Qt::Key_Plus), this, SLOT(increaseFontSize()));
    new QShortcut(QKeySequence(Qt::Key_Minus), this, SLOT(decreaseFontSize()));

    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(const QPoint&)));

    loadStockData();

    // launch thread that refreshes MainWindow while it is being displayed
    std::thread tempRefresher(refreshTicker,ui);
    tempRefresher.detach();

}

MainWindow::~MainWindow() { delete ui; }

// increase or decrease font size of MainWindow ticker list
void MainWindow::changeFontSize(bool increase) {
    fontSize = ui->symbolColumn->fontInfo().pointSize();
    if (increase)
        ++fontSize;
    else
        if (fontSize >= 7)
            --fontSize;

    ui->symbolColumn->setFont(QFont(currentFont,fontSize));
    ui->priceColumn->setFont(QFont(currentFont,fontSize));
    ui->changColumn->setFont(QFont(currentFont,fontSize));
    this->adjustSize();

}

void MainWindow::increaseFontSize() { return changeFontSize(true); }
void MainWindow::decreaseFontSize() { return changeFontSize(false); }

// opens custom right-click context menu
void MainWindow::showContextMenu(const QPoint& pos) {

    QMenu rightClickMenu(this);
    QAction actionSet("Settings\tS", this);
    QAction actionAbo("About\tA", this);
    QAction actionExit("Exit\tCtrl+Q", this);

    connect(&actionSet, SIGNAL(triggered(bool)), this, SLOT(openSettings()));
    connect(&actionAbo, SIGNAL(triggered(bool)), this, SLOT(openAbout()));
    connect(&actionExit, SIGNAL(triggered(bool)), this,SLOT(endProgram()));

    rightClickMenu.addAction(&actionSet);
    rightClickMenu.addAction(&actionAbo);
    rightClickMenu.addSeparator();
    rightClickMenu.addAction(&actionExit);
    rightClickMenu.exec(mapToGlobal(pos));

}

void MainWindow::openSettings() { settingsDia.show(); }
void MainWindow::openAbout() { aboutDialog.show(); }

// save position of clicked mouse
// right-click: request custom context menu
void MainWindow::mousePressEvent(QMouseEvent *event){
    mpos = event->pos();
    if(event->button() == Qt::RightButton)
        emit customContextMenuRequested(mpos);

}

// holding a left-click will make the window move:
void MainWindow::mouseMoveEvent(QMouseEvent *event){

    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;
        setCursor(QCursor(Qt::SizeAllCursor));
        this->move(newpos);
    }

}


// reset cursor icon after releasing left mouse button
void MainWindow::mouseReleaseEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton)
        unsetCursor();

}


// reload Ticker information and update graphical interface
void MainWindow::loadStockData() {

    instance = Ticker::getInstance();

    ui->symbolColumn->setText(instance.symbolsToString());
    ui->priceColumn->setText(instance.priceToString());
    ui->changColumn->setText(instance.changeToString());

}

// send program exit signal
// upon closing MainWindow all open windows will be closed
void MainWindow::endProgram() {
    emit exitProg();
}





