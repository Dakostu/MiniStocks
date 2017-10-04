/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "Ticker.h"
#include "TickerItem.h"
#include "FileUtils.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QStandardPaths>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>


typedef std::vector<TickerItem>::iterator TickItemIt;

const QString defaultTickers[] = {"^SPX","AAPL","GOOG","CL=F","GC=F","EURUSD=X"};
std::vector<TickerItem> Ticker::ticker;
// Ticker is instantiated by either creating a default or loading savefile
Ticker::Ticker() {

    Ticker::ticker.clear();
    // default Ticker
    if (!checkifFile(savename)) {
        for (unsigned i = 0; i < (sizeof(defaultTickers) / sizeof(*defaultTickers)); ++i)
            Ticker::ticker.push_back(TickerItem(defaultTickers[i]));
        saveFile(savename,getAllTickerSymbols());
    // loaded Ticker
    } else {
        std::vector<QString> savedTickers = loadFile(savename);
        for (std::vector<QString>::iterator it = savedTickers.begin(); it != savedTickers.end(); ++it)
            if (it->length())
                Ticker::ticker.push_back(TickerItem(*it));
    }

}


Ticker& Ticker::getInstance() {
    static Ticker t;
    t.refresh();
    return t;
}


void Ticker::refresh() {

    std::vector<QString> savedTickers = loadFile(savename);
    std::vector<TickerItem> tempTickers;
    for (std::vector<QString>::iterator it = savedTickers.begin(); it != savedTickers.end(); ++it)
        if (it->length())
            tempTickers.push_back(TickerItem(*it));


    /*for (TickItemIt it = tempTickers.begin(); it != tempTickers.end(); ++it)
            it->loadItemData();
    for (TickItemIt it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it)
        it->loadItemData();*/

}


std::vector<QString> Ticker::getAllTickerSymbols() {

    std::vector<QString> symbVec;
    for (TickItemIt it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it)
        symbVec.push_back(it->gettickerSymbol());
    return symbVec;

}


QString Ticker::dataToString(const WhatData& whatData) {
    std::vector<QString> tempVec;
    TickItemIt it;
    switch (whatData) {
    case (SYMBOLS):
        for (it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it)
            tempVec.push_back(it->gettickerSymbol());
        break;
    case (PRICES):
        for (it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it)
            tempVec.push_back(it->getPrice());
        break;
    case (CURRENCIES):
        for (it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it)
            tempVec.push_back(it->getCurrency());
        break;
    case (CHANGES):
        for (it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it)
            tempVec.push_back(it->getChange());
        break;
    default:
        return NULL;
        break;

    }

    QString str("<pre>");
    for (std::vector<QString>::iterator it = tempVec.begin(); it != tempVec.end(); ++it) {
        str += *it;
        str += (it < tempVec.end()-1) ? "<br>" : "</pre>";
    }
    return str;

}

QString Ticker::symbolsToString() { return dataToString(SYMBOLS); }
QString Ticker::priceToString() { return dataToString(PRICES); }
QString Ticker::currencyToString() { return dataToString(CURRENCIES); }
QString Ticker::changeToString() { return dataToString(CHANGES); }

QString Ticker::toString() {

    QString str("<pre>");
    for (TickItemIt it = Ticker::ticker.begin(); it != Ticker::ticker.end(); ++it) {
        str += it->toString();
        str += (it < Ticker::ticker.end()-1) ? "<br>" : "</pre>";
    }
    return str;

}


