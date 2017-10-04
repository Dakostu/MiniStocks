#include "TickerRefreshThread.h"
#include <unistd.h>
#include <QApplication>

void refreshTicker(Ui::MainWindow *ui) {

    while (1) {

        Ticker instance = Ticker::getInstance();

        ui->symbolColumn->setText(instance.symbolsToString());
        ui->priceColumn->setText(instance.priceToString());
        ui->curColumn->setText(instance.currencyToString());
        ui->changColumn->setText(instance.changeToString());
        qApp->processEvents();


        sleep(0.2);
    }

    return;
}
