#include "TickerItem.h"
#include "Ticker.h"
#include "TickerRefreshThread.h"
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "SettingsDialog.h"
#include "About.h"
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


    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(const QPoint&)));

    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(endProgram()));
    new QShortcut(QKeySequence(Qt::Key_A), this, SLOT(openAbout()));
    new QShortcut(QKeySequence(Qt::Key_S), this, SLOT(openSettings()));
    new QShortcut(QKeySequence(Qt::Key_Plus), this, SLOT(increaseFontSize()));
    new QShortcut(QKeySequence(Qt::Key_Minus), this, SLOT(decreaseFontSize()));

    loadStockData();

    std::thread refresher(refreshTicker,ui);
    refresher.detach();


}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::changeFontSize(bool increase) {
    fontSize = ui->symbolColumn->fontInfo().pointSize();
    if (increase)
        ++fontSize;
    else
        if (fontSize >= 7)
            --fontSize;

    ui->symbolColumn->setFont(QFont(currentFont,fontSize));
    ui->priceColumn->setFont(QFont(currentFont,fontSize));
    ui->curColumn->setFont(QFont(currentFont,fontSize));
    ui->changColumn->setFont(QFont(currentFont,fontSize));
    this->adjustSize();

}

void MainWindow::increaseFontSize() { return changeFontSize(true); }
void MainWindow::decreaseFontSize() { return changeFontSize(false); }

void MainWindow::showContextMenu(const QPoint& pos) {

    QMenu rightClickMenu(this);
    //QAction actionMove("Move", this);
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

void MainWindow::openSettings() { SettingsDialog::getInstance().show(); }
void MainWindow::openAbout() { About::getInstance().show(); }

void MainWindow::mousePressEvent(QMouseEvent *event){
    mpos = event->pos();
    if(event->button() == Qt::RightButton)
            emit customContextMenuRequested(mpos);

}
void MainWindow::mouseMoveEvent(QMouseEvent *event){

    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;
        setCursor(QCursor(Qt::SizeAllCursor));
        this->move(newpos);
    }

}



void MainWindow::mouseReleaseEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton)
        unsetCursor();

}


void MainWindow::loadStockData() {

    instance = Ticker::getInstance();
    ui->symbolColumn->clear();
    ui->priceColumn->clear();
    ui->curColumn->clear();
    ui->changColumn->clear();

    ui->symbolColumn->setText(instance.symbolsToString());
    ui->priceColumn->setText(instance.priceToString());
    ui->curColumn->setText(instance.currencyToString());
    ui->changColumn->setText(instance.changeToString());


}

#include <QApplication>
void MainWindow::endProgram() {

    emit exitProg();

}

