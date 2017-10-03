#ifndef TICKER_H
#define TICKER_H

#include "TickerItem.h"
#include <vector>
#include <QThread>


enum WhatData {Symbols, Prices, Currencies, Changes};

class Ticker {
    static std::vector<TickerItem> ticker;
    QString dataToString(const WhatData &whatData);
    Ticker();
    static void refresh();


public:    
    std::vector<QString> getAllTickerSymbols();    
    QString symbolsToString();
    QString priceToString();
    QString currencyToString();
    QString changeToString();
    QString toString();
    static Ticker& getInstance();

};

#endif
