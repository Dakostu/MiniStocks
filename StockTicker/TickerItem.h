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
#ifdef HAS_CURL
    #include "curl/curl.h"
#endif


class TickerItem {

    QString tickerSymbol;
    double value;
    QString currency;
    double change;
    QString changeColor;
    QString sign;
    QString toDownload;
    QString quotes;
    std::vector<QString> parsedCSV;
#ifdef HAS_CURL
    CURL *curl;
    FILE *fp;
#endif

    void downloadData(const QString &url, const QString &filepath);
    void parseCSVintoVector(std::istream& csv);
    void downloadAndParseCSVFile(const QString &ticker);
    void assignComponents(std::vector<QString> &parsedCSV);

public:
    explicit TickerItem(QString symbol);
    QString toString();
    QString gettickerSymbol();
    QString getPrice();
    QString getChange();
    void loadItemData();

protected:

};


#endif
