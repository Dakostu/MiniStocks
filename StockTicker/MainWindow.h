#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <thread>
#include "Ticker.h"
#include "TickerRefreshThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadStockData();

private:


    Ui::MainWindow *ui;
    Ticker instance = Ticker::getInstance();
    QPoint mpos;

    void changeFontSize(bool increase);

protected:
    QString currentFont;
    unsigned fontSize;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


public slots:
    void showContextMenu(const QPoint& pos);
    void increaseFontSize();
    void decreaseFontSize();
    void openSettings();
    void openAbout();
    void endProgram();

signals:
    void customContextMenuRequested(const QPoint &pos);
    void exitProg();


};

#endif // MAINWINDOW_H
