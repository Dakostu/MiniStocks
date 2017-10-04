/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#ifndef TICKERITEM_H
#define TICKERITEM_H

#include <QString>
#include <vector>
#include <fstream>
#include "curl/curl.h"

class TickerItem {

    QString tickerSymbol;
    double value;
    QString currency;
    double change;
    std::vector<QString> parsedCSV;


    void assignComponents(std::vector<QString> &parsedCSV);

public:
    TickerItem(QString symbol);
    QString toString();
    QString gettickerSymbol();
    QString getPrice();
    QString getCurrency();
    QString getChange();
    void loadItemData();

protected:
    CURL *curl;
    FILE *fp;
    QString changeColor;
    QString sign;
    QString toDownload;
    QString quotes;

    void downloadData(const QString &url, const QString &filepath);
    std::vector<QString> parseCSVintoVector (std::istream& csv);
    std::vector<QString> downloadAndParseCSVFile(const QString &ticker);

};


#endif
