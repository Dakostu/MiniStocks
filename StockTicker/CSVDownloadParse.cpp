#include "CSVDownloadParse.h"
#include "FileUtils.h"
#include "curl/curl.h"
#include <QDebug>
#include <QFile>
#include <string>
#include <fstream>
#include <memory>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QMessageBox>
#include <QStandardPaths>
#include <QEventLoop>
#include <QFileInfo>

void downloadFile(const QString &url, const QString &filepath) {

    makeSaveDir();

    CURL *curl;
    FILE *fp;

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

/*


    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;

    QObject::connect (reply, SIGNAL(finished()),&loop, SLOT(quit()));


    loop.exec();

    QString path = QUrl(url).path();
    //QString basename = QFileInfo(path).fileName();

    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());
    file.close();

    reply->deleteLater();

}*/




// parses raw CSV data and saves it into a vector
std::vector<QString> parseCSVintoVector (std::istream& csv) {

    std::vector<QString> vec;
    std::string line;


    // Yahoo Finance CSV data is separated with a comma
    while (std::getline(csv,line,','))
        vec.push_back(QString::fromStdString(line));

    return std::vector<QString>(vec);

}

// combine downloadFile and parseCSVintoVector to download stock information
std::vector<QString> downloadAndParseCSVFile(const QString &ticker) {

    // download & save CSV file from Yahoo Finance
    // l1 = Last Trade Price
    // c4 = Currency
    // p2 = Change in Percent
    // See: http://www.canbike.org/information-technology/yahoo-finance-url-download-to-a-csv-file.html
    const QString toDownload("l1c4p2");
    const QString quotes("http://download.finance.yahoo.com/d/quotes.csv?s=" + ticker
                         + "&f=" + toDownload + "&e=.csv");
    try {
        downloadFile(quotes, saveDir + "/quotes.csv");
    } catch (...) {
        qDebug() << "CSV for " << ticker << " cannot be downloaded.";
        std::vector<QString> empty;
        return empty;
    }


    // parse CSV file & delete the file afterwards
    std::ifstream csvFile(csvFileLocation.toStdString());
    std::vector<QString> parsedCSV = parseCSVintoVector(csvFile);
    //QFile::remove(csvFileLocation);


    return parsedCSV;

}

