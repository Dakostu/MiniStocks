#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <vector>
#include <QString>
#include <QStandardPaths>

typedef const QString constStr;

extern constStr saveDir;
extern constStr savename;
extern constStr tempfile;
extern constStr csvFileLocation;
extern constStr settingsFile;

bool checkifFile(constStr &filename);
std::vector<QString> loadFile(constStr &filename);
bool saveFile(constStr &filename, std::vector<QString> vec);
void makeSaveDir();


#endif // FILEUTILS_H
