#include "TickerRefreshThread.h"
#include <unistd.h>
#include <QLabel>

void refreshTicker(Ui::MainWindow *ui) {

    while (1) {

        Ticker instance = Ticker::getInstance();
        /*ui->symbolColumn->clear();
        ui->priceColumn->clear();
        ui->curColumn->clear();
        ui->changColumn->clear();*/
        ui->symbolColumn->setText(instance.symbolsToString());
        ui->priceColumn->setText(instance.priceToString());
        ui->curColumn->setText(instance.currencyToString());
        ui->changColumn->setText(instance.changeToString());



        sleep(0.2);
    }

    return;
}
