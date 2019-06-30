/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all declarations for the TickerInfoDownloader class.
 * The TickerInfoDownloader class downloads the newest stock price info for a single ticker.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#ifndef TICKERINFODOWNLOADER_H
#define TICKERINFODOWNLOADER_H

#ifdef HAS_CURL
    #include "curl/curl.h"
#endif

#include <QString>
#include <fstream>
#include <vector>

class TickerInfoDownloader
{
#ifdef HAS_CURL
    CURL *curl;
    FILE *fp;
#endif

    const QString tickerSymbol;
    void downloadData(const QString &url, const QString &filepath);
    std::vector<QString> parseCSVintoVector(std::istream& csv);
    void downloadAndParseCSVFile();
    std::vector<QString> stockData;

public:    
    TickerInfoDownloader(const QString &ticker);
    std::vector<QString> getData();
};

#endif // TICKERINFODOWNLOADER_H
