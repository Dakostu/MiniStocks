/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "File.h"
#include "TickerItem.h"
#include "QStringCSSUtils.h"
#include <QFile>
#include <QDebug>
#include <string>

// A TickerItem is instantiated by downloading newest data and assigning it to components
TickerItem::TickerItem(QString symbol) : tickerSymbol(symbol.toUpper()), infoDownloader(tickerSymbol) {
    loadItemData();
}

// assigns parsed data from CSV file to TickerItem components
void TickerItem::assignComponents(std::vector<QString> &parsedCSV) {

    try {
        value = parsedCSV.at(2).toDouble();
        change = (value - parsedCSV.at(1).toDouble()) / value;
    } catch (const std::exception& e) { // Spelling error? Connection problems? Stock not existing anymore?
        qDebug() << tickerSymbol << ":\t TickerItem can not be loaded";
        qDebug() << e.what();
        return;
    }

    return;

}

// Obvious getter methods
QString TickerItem::gettickerSymbol() { return tickerSymbol.mid(0,9); }

QString TickerItem::getPrice() { return QString::number(value,'d',2);}

QString TickerItem::getChange() {
    changeColor = (change < 0 ) ? "red" : "green";
    sign = (change >= 0) ? "+" : "";
    return ("(" + colorizeText(sign + QString::number(change,'d',2)+"%", changeColor) + ")");
}

// Old toString method, for debug purposes
QString TickerItem::toString() {

    // Percentage shall be either in green or red color, depending on sign
    changeColor = (change < 0 ) ? "red" : "green";
    sign = (change >= 0) ? "+" : "";

    return tickerSymbol.mid(0,9) + tab
            + QString::number(value,'d',2) + tab + currency
            + tab + "("
            + colorizeText(sign + QString::number(change,'d',2)+"%", changeColor)
            + ")";

}

// load new data
void TickerItem::loadItemData() {
    itemData = infoDownloader.getData();
    assignComponents(itemData);
}
