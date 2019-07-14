/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all declarations for the TickerItem class.
 * The TickerItem class parses the downloaded stock data into a displayable string.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#ifndef TICKERITEM_H
#define TICKERITEM_H

#include "TickerInfoDownloader.h"
#include <QString>
#include <vector>

class TickerItem {

    QString tickerSymbol;
    double value;
    QString currency;
    double change;
    QString changeColor;
    QString sign;
    std::vector<QString> itemData;

    TickerInfoDownloader infoDownloader;

    QString buildColorblock (const QString &color);
    QString colorizeText (const QString &message, const QString &color);

public:
    explicit TickerItem(QString symbol);
    QString toString();
    QString gettickerSymbol();
    QString getPrice();
    QString getChange();
    std::vector<QString> downloadItemData();
    void assignNewItemData(std::vector<QString> &parsedCSV);

protected:

};


#endif
