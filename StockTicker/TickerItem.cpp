/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "File.h"
#include "TickerItem.h"
#include "QStringCSSUtils.h"
#include <QFile>
#include <QDebug>
#ifdef HAS_CURL
    #include "curl/curl.h"
#else
    #include <QNetworkAccessManager>
    #include <QNetworkReply>
    #include <QEventLoop>
    #include <QNetworkRequest>
    #include <QMessageBox>
    #include <QFileInfo>
    #include <QObject>
#endif
#include <string>

// A TickerItem is instantiated by downloading newest data and assigning it to components
TickerItem::TickerItem(QString symbol) {

    downloadAndParseCSVFile(symbol = symbol.toUpper());
    tickerSymbol = symbol;
    assignComponents(parsedCSV);

}

// assigns parsed data from CSV file to TickerItem components
void TickerItem::assignComponents(std::vector<QString> &parsedCSV) {

    try {
        value = parsedCSV.at(2).toDouble();
        change = (value - parsedCSV.at(1).toDouble()) / value;
    } catch (const std::exception& e) { // Spelling error? Connection problems? Stock not existing anymore?
        qDebug() << tickerSymbol << ":\t TickerItem can not be loaded";
        qDebug() << e.what();
        return;
    }

    return;

}

// Obvious getter methods
QString TickerItem::gettickerSymbol() { return tickerSymbol.mid(0,9); }

QString TickerItem::getPrice() { return QString::number(value,'d',2);}

QString TickerItem::getChange() {
    changeColor = (change < 0 ) ? "red" : "green";
    sign = (change >= 0) ? "+" : "";
    return ("(" + colorizeText(sign + QString::number(change,'d',2)+"%", changeColor) + ")");
}

// Old toString method, for debug purposes
QString TickerItem::toString() {

    // Percentage shall be either in green or red color, depending on sign
    changeColor = (change < 0 ) ? "red" : "green";
    sign = (change >= 0) ? "+" : "";

    return tickerSymbol.mid(0,9) + tab
            + QString::number(value,'d',2) + tab + currency
            + tab + "("
            + colorizeText(sign + QString::number(change,'d',2)+"%", changeColor)
            + ")";

}


// load new data
void TickerItem::loadItemData() {

    parsedCSV.clear();
    downloadAndParseCSVFile(tickerSymbol);
    assignComponents(parsedCSV);

}

void TickerItem::downloadData(const QString &url, const QString &filepath) {

    makeSaveDir();

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
void TickerItem::parseCSVintoVector (std::istream& csv) {

    std::string line;

    // IEXTradingData consists of two lines:
    while (std::getline(csv,line,','))
        parsedCSV.push_back(QString::fromStdString(line));

}

// combine downloadData and parseCSVintoVector to download stock information
void TickerItem::downloadAndParseCSVFile(const QString &ticker) {

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
