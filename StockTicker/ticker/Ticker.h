/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all declarations for the Ticker class.
 * The Ticker class is the class that saves/loads all Ticker item data and displays them.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#ifndef TICKER_H
#define TICKER_H

#include "TickerItem.h"
#include <vector>
#include <QThread>


enum WhatData {SYMBOLS, PRICES, CHANGES};

class Ticker {
    static std::vector<TickerItem> ticker;

    QString dataToString(const WhatData &whatData);
    Ticker();
    static void refresh();


public:    
    std::vector<QString> getAllTickerSymbols();    
    QString symbolsToString();
    QString priceToString();
    QString changeToString();
    QString toString();
    static Ticker& getInstance();

};

#endif
