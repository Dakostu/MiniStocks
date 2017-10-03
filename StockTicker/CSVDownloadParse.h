#ifndef CSVDOWNLOADPARSE_H
#define CSVDOWNLOADPARSE_H

#include <vector>
#include <fstream>
#include <QString>



void downloadFile(const QString &url, const QString &filepath);
std::vector<QString> parseCSVintoVector (std::istream& csv);
std::vector<QString> downloadAndParseCSVFile(const QString &ticker);


#endif
