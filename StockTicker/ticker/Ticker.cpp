/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the Ticker class.
 * The Ticker class is the Singleton class that saves/loads all Ticker item data and displays them.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "../file/File.h"
#include "Ticker.h"
#include "TickerItem.h"
#include <QFile>
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>


static const std::vector<QString> defaultTickers = {"^SPX","AAPL.US","GOOG.US","CL.F","GC.F","EURUSD"};

std::vector<TickerItem> Ticker::ticker;
std::vector<QString> Ticker::loadedTickerSymbols;
File Ticker::savedTickers(File::getSaveName());

// Ticker is instantiated by either creating a default or loading savefile
Ticker::Ticker() {

    loadedTickerSymbols = loadTickerSymbolsFromSettingsFile();

}

Ticker::~Ticker() {
    File savedTickers(File::getSaveName());
    savedTickers.saveContentsToFile(loadedTickerSymbols);
}

std::vector<QString> Ticker::loadTickerSymbolsFromSettingsFile() {

    ticker.clear();

    std::vector<QString> tempTickerSymbols;
    // load Ticker from file, if the file doesn't exist, use the default
    if (savedTickers.fileIsValid()) {
        tempTickerSymbols = savedTickers.loadContents();
    } else {
        tempTickerSymbols = defaultTickers;
    }

    return tempTickerSymbols;

}

Ticker& Ticker::getInstance() {

    static Ticker t;
    t.refresh();
    return t;

}

void Ticker::refresh() {

    loadTickersFromVector(loadedTickerSymbols);

}


void Ticker::loadTickersFromVector(const std::vector<QString> &tickerVec) {

    if (tickerVec.empty())
        return;

    ticker.clear();
    for (auto tickerItem : tickerVec) {
        TickerItem temp(tickerItem);
        auto tempInfo = temp.downloadItemData();
        temp.assignNewItemData(tempInfo);
        ticker.emplace_back(temp);
    }

}

std::vector<QString> Ticker::getAllTickerSymbols() {

    std::vector<QString> symbVec;
    for (auto tickerItem : ticker)
        symbVec.emplace_back(tickerItem.gettickerSymbol());
    return symbVec;

}

QString Ticker::dataToString(const WhatData& whatData) {

    std::vector<std::function<QString(TickerItem)>> dataCallbacks
                                                 = {&TickerItem::gettickerSymbol,
                                                    &TickerItem::getPrice,
                                                    &TickerItem::getChange};

    std::vector<QString> tempVec;

    for (auto tickerItem : ticker)
        tempVec.emplace_back(dataCallbacks.at(whatData)(tickerItem));

    QString str("<pre>");
    for (auto it = tempVec.begin(); it != tempVec.end(); ++it) {
        str += *it;
        str += (it < tempVec.end()-1) ? "<br>" : "</pre>";
    }

    return str;

}

QString Ticker::symbolsToString() { return dataToString(SYMBOLS); }
QString Ticker::priceToString() { return dataToString(PRICES); }
QString Ticker::changeToString() { return dataToString(CHANGES); }

QString Ticker::toString() {

    QString str("<pre>");
    for (auto it = ticker.begin(); it != ticker.end(); ++it) {
        str += it->toString();
        str += (it < ticker.end()-1) ? "<br>" : "</pre>";
    }
    return str;

}


