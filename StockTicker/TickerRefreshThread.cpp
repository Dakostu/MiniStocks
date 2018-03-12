#include "TickerRefreshThread.h"
#include <unistd.h>
#include <QApplication>
#include <QLabel>

void refreshTicker(Ui::MainWindow *ui) {

    while (1) {
        Ticker instance = Ticker::getInstance();

        ui->symbolColumn->setText(instance.symbolsToString());
        ui->priceColumn->setText(instance.priceToString());
        ui->changColumn->setText(instance.changeToString());

        sleep(0.2);
    }

    return;
}
