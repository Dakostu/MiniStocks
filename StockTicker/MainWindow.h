#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "signalmachine.h"
#include "Ticker.h"
#include <QMainWindow>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:


    Ui::MainWindow *ui;
    Ticker instance = Ticker::getInstance();
    QPoint mpos;
    SignalMachine sigmach;


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
    void loadStockData();

signals:
    void customContextMenuRequested(const QPoint &pos);
    void exitProg();
    void launchSigMach();


};

#endif // MAINWINDOW_H
