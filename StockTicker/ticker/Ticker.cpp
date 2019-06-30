/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the Ticker class.
 * The Ticker class is the class that saves/loads all Ticker item data and displays them.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "../file/File.h"
#include "Ticker.h"
#include "TickerItem.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QStandardPaths>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>


static const std::vector<QString> defaultTickers = {"^SPX","AAPL.US","GOOG.US","CL.F","GC.F","EURUSD"};

std::vector<TickerItem> Ticker::ticker;
// Ticker is instantiated by either creating a default or loading savefile
Ticker::Ticker() {

    ticker.clear();

    File savedTickers(File::getSaveName());

    // load Ticker from file, if the file doesn't exist, use the default
    if (savedTickers.fileIsValid()) {
        auto savedTickerItems = savedTickers.loadContents();
        for (auto tickerItem : savedTickerItems) {
            ticker.emplace_back(tickerItem);
        }
    } else {
        savedTickers.saveContentsToFile(defaultTickers);
    }

}


Ticker& Ticker::getInstance() {

    static Ticker t;
    t.refresh();
    return t;

}


void Ticker::refresh() {

    File savedTickers(File::getSaveName());

    auto savedTickerItems = savedTickers.loadContents();
    if (savedTickerItems.empty())
        return;

    ticker.clear();
    for (auto tickerItem : savedTickerItems) {
        ticker.emplace_back(tickerItem);
    }

}


std::vector<QString> Ticker::getAllTickerSymbols() {

    std::vector<QString> symbVec;
    for (auto tickerItem : ticker)
        symbVec.emplace_back(tickerItem.gettickerSymbol());
    return symbVec;

}


QString Ticker::dataToString(const WhatData& whatData) {

    std::vector<QString> tempVec;
    switch (whatData) {
    case (SYMBOLS):
        for (auto tickerItem : ticker)
            tempVec.emplace_back(tickerItem.gettickerSymbol());
        break;
    case (PRICES):
        for (auto tickerItem : ticker)
            tempVec.emplace_back(tickerItem.getPrice());
        break;
    case (CHANGES):
        for (auto tickerItem : ticker)
            tempVec.emplace_back(tickerItem.getChange());
        break;
    }

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


