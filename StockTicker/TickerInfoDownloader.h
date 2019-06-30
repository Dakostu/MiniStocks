#ifndef TICKERINFODOWNLOADER_H
#define TICKERINFODOWNLOADER_H

#ifdef HAS_CURL
    #include "curl/curl.h"
#endif

#include <QString>
#include <fstream>

class TickerInfoDownloader
{
#ifdef HAS_CURL
    CURL *curl;
    FILE *fp;
#endif

    const QString tickerSymbol;

public:    
    TickerInfoDownloader(const QString &ticker);

    void downloadData(const QString &url, const QString &filepath);
    void parseCSVintoVector(std::istream& csv);
    void downloadAndParseCSVFile(const QString &ticker);
};

#endif // TICKERINFODOWNLOADER_H
