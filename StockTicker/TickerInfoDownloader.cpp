#include "File.h"
#include "TickerInfoDownloader.h"
#include <QDebug>

TickerInfoDownloader::TickerInfoDownloader(const QString &ticker) : tickerSymbol(ticker)
{

}


void TickerInfoDownloader::downloadData(const QString &url, const QString &filepath) {
    File::makeSaveDir();

#ifdef HAS_CURL

    if ((curl = curl_easy_init())) {
        fp = fopen(filepath.toLatin1().data(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.toLatin1().data());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_callback());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
        return;
    }

    throw;

}
#else
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QEventLoop loop;
    QString path;

    QNetworkRequest request(url);
    reply = manager.get(request);

    QObject::connect (reply, SIGNAL(finished()),&loop, SLOT(quit()));

    loop.exec();

    path = QUrl(url).path();

    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());
    file.close();

    reply->deleteLater();

}
#endif

// parses raw CSV data and saves it into the TckerItem vector
std::vector<QString> TickerInfoDownloader::parseCSVintoVector(std::istream& csv) {
    std::string line;
    std::vector<QString> parsedCSV;

    // IEXTradingData consists of two lines:
    while (std::getline(csv,line,','))
        parsedCSV.emplace_back(line);

    return parsedCSV;
}

void TickerInfoDownloader::downloadAndParseCSVFile() {
    auto fileName = "/quotes/" + tickerSymbol + ".csv";
    auto csvFileLocation = File::getFileInSaveDir(fileName);
    // download & save JSON file from Stooq
    auto quotes = "https://stooq.com/q/l/?s=" + tickerSymbol + "&f=soc&e=csv";
    try {
        downloadData(quotes, csvFileLocation);
    } catch (...) {
        qDebug() << "new CSV file for " << tickerSymbol << " cannot be downloaded.";
        return;
    }


    // parse CSV file & delete it afterwards
    std::ifstream csvFile(csvFileLocation.toStdString());
    this->stockData = parseCSVintoVector(csvFile);
    QFile::remove(csvFileLocation);
}

std::vector<QString> TickerInfoDownloader::getData() {
    downloadAndParseCSVFile();
    return this->stockData;
}
