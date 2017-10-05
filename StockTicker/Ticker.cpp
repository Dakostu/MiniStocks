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

    ticker.clear();
    // default Ticker
    if (!checkifFile(savename)) {
        for (unsigned i = 0; i < (sizeof(defaultTickers) / sizeof(*defaultTickers)); ++i)
            ticker.push_back(TickerItem(defaultTickers[i]));
        saveFile(savename,getAllTickerSymbols());
    // loaded Ticker
    } else {
        std::vector<QString> savedTickers = loadFile(savename);
        for (std::vector<QString>::iterator it = savedTickers.begin(); it != savedTickers.end(); ++it)
            if (it->length())
                ticker.push_back(TickerItem(*it));
    }

}


Ticker& Ticker::getInstance() {
    static Ticker t;
    t.refresh();
    return t;
}


void Ticker::refresh() {

    std::vector<QString> savedTickers = loadFile(savename);
    ticker.clear();
    for (std::vector<QString>::iterator it = savedTickers.begin(); it != savedTickers.end(); ++it)
        if (it->length())
            ticker.push_back(TickerItem(*it));



}


std::vector<QString> Ticker::getAllTickerSymbols() {

    std::vector<QString> symbVec;
    for (TickItemIt it = ticker.begin(); it != ticker.end(); ++it)
        symbVec.push_back(it->gettickerSymbol());
    return symbVec;

}


QString Ticker::dataToString(const WhatData& whatData) {
    std::vector<QString> tempVec;
    TickItemIt it;
    switch (whatData) {
    case (SYMBOLS):
        for (it = ticker.begin(); it != ticker.end(); ++it)
            tempVec.push_back(it->gettickerSymbol());
        break;
    case (PRICES):
        for (it = ticker.begin(); it != ticker.end(); ++it)
            tempVec.push_back(it->getPrice());
        break;
    case (CURRENCIES):
        for (it = ticker.begin(); it != ticker.end(); ++it)
            tempVec.push_back(it->getCurrency());
        break;
    case (CHANGES):
        for (it = ticker.begin(); it != ticker.end(); ++it)
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
    for (TickItemIt it = ticker.begin(); it != ticker.end(); ++it) {
        str += it->toString();
        str += (it < ticker.end()-1) ? "<br>" : "</pre>";
    }
    return str;

}


