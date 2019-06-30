/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the Ticker refresh thread.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

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

        sleep(1);
    }

    return;
}
