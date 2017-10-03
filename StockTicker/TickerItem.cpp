#include "TickerItem.h"
#include "CSVDownloadParse.h"   // downloadAndParseCSVFile()
#include "QStringCSSUtils.h"    // colorizeText();
#include <QStandardPaths>
#include <QFile>
#include <QDebug>



// TickerItem is instantiated by downloading newest data and assigning it to components
TickerItem::TickerItem(QString symbol) {

    parsedCSV = downloadAndParseCSVFile(symbol = symbol.toUpper());
    tickerSymbol = symbol;
    assignComponents(parsedCSV);


}


// assigns parsed data from CSV file to TickerItem components
void TickerItem::assignComponents(std::vector<QString> &parsedCSV) {

    try {
        value = parsedCSV.at(0).toDouble();
        currency = removeStringToken(parsedCSV.at(1), quotMark);
        change = stringIntoDoubleRounded(removeStringToken(parsedCSV.at(2), quotMark));
    } catch (...) { // Spelling error? Connection problems? Stock not existing anymore?
        //value = change = 0;
        //currency = "---";
        qDebug() << tickerSymbol << "\t TickerItem can not be loaded";
    }

    return;
}


// This one is obvious
QString TickerItem::gettickerSymbol() { return tickerSymbol.mid(0,9); }

QString TickerItem::getPrice() { return QString::number(value,'d',2);}

QString TickerItem::getCurrency() { return currency; }

QString TickerItem::getChange() {
    const QString changeColor = (change < 0 ) ? "red" : "green";
    const QString sign = (change >= 0) ? "+" : "";
    return ("(" + colorizeText(sign + QString::number(change,'d',2)+"%", changeColor) + ")");
}


QString TickerItem::toString() {
    // Percentage shall be either in green or red color, depending on sign
    const QString changeColor = (change < 0 ) ? "red" : "green";
    const QString sign = (change >= 0) ? "+" : "";

    return tickerSymbol.mid(0,9) + tab
            + QString::number(value,'d',2) + tab + currency
            + tab + "("
            + colorizeText(sign + QString::number(change,'d',2)+"%", changeColor)
            + ")";

}

void TickerItem::loadItemData() {
    parsedCSV.clear();
    parsedCSV = downloadAndParseCSVFile(tickerSymbol);
    assignComponents(parsedCSV);


}
