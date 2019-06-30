#include "File.h"
#include "TickerInfoDownloader.h"

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
void TickerInfoDownloader::parseCSVintoVector(std::istream& csv) {
    std::string line;

    // IEXTradingData consists of two lines:
    while (std::getline(csv,line,','))
        parsedCSV.push_back(QString::fromStdString(line));
}

void TickerInfoDownloader::downloadAndParseCSVFile(const QString &ticker) {
    auto csvFileLocation = File::getFileInSaveDir("/quotes.csv");
    // download & save JSON file from Stooq
    quotes = "https://stooq.com/q/l/?s=" + ticker + "&f=soc&e=csv";
    try {
        downloadData(quotes, csvFileLocation);
    } catch (...) {
        qDebug() << "new CSV file for " << ticker << " cannot be downloaded.";
        return;
    }


    // parse CSV file & delete it afterwards
    std::ifstream csvFile(csvFileLocation.toStdString());
    parseCSVintoVector(csvFile);
    QFile::remove(csvFileLocation);

}
