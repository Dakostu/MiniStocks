/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "FileUtils.h"
#include <QFile>
#include <QDir>
#include <QSaveFile>
#include <QTextStream>
#include <fstream>


constStr saveDir = (QStandardPaths::writableLocation(QStandardPaths::HomeLocation))
        + "/.ministocks";  // location of all MiniStocks save and temp files
constStr savename = saveDir + "/savedtickers";
constStr tempfile = saveDir + "/tmp.bak";
constStr CSVFileLocation = saveDir + "/quotes.csv";
constStr settingsFile = saveDir + "/settings";


// Assign pointer to savefile and check if the file can be opened & contains info
bool checkifFile(constStr &filename) {

    QFile file(filename);
    return (file.exists() && file.size() && !file.error());

}


// Load file by loading lines containing ticker name, line by line
std::vector<QString> loadFile(constStr &filename) {
    makeSaveDir();

    QFile file(filename);
    std::vector<QString> tickVec;
    file.open(QIODevice::ReadOnly);

    while (!file.atEnd())
        tickVec.push_back(file.readLine().trimmed()); // trimmed(): Remove linebreak

    return tickVec;

}


// Save Ticker names into a plaintext file
bool saveFile(constStr &filename, std::vector<QString> vec) {
    makeSaveDir();

    std::ofstream save(filename.toStdString());

    for (std::vector<QString>::iterator it = vec.begin(); it != vec.end(); ++it)
        save << it->toStdString()<< "\n";


    save.close();
    return true;
}

// if designated directory does not exist, create one
void makeSaveDir() {

    if (!QDir(saveDir).exists())
        QDir().mkdir(saveDir);

}
