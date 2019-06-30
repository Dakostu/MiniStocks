#include "File.h"
#include <fstream>
#include <QDir>
#include <QException>

File::File(constStr &fileName) : file(fileName){
    this->fileName = fileName;    
}


File::~File() {
    if (file.isOpen()) {
        file.close();
    }
}


bool File::fileIsValid() {
    return (file.exists() && !file.error());
}


std::vector<QString> File::loadContents() {

    if (!fileIsValid()) {
        throw "file " + fileName + " is not a valid file";
    }

    file.open(QIODevice::ReadOnly);

    if (!file.isReadable()) {
        throw "file " + fileName + " is not readable";
    }

    std::vector<QString> contentsVec;
    while (!file.atEnd())
        contentsVec.emplace_back(file.readLine().trimmed()); // trimmed(): Remove linebreak

    file.close();
    return contentsVec;
}


bool File::saveContentsToFile(const std::vector<QString> &vec) {
    File::makeSaveDir();
    file.open(QIODevice::WriteOnly);

    if (!file.isWritable()) {
        return false;
    }

    for (auto line : vec) {
        file.write(line.toUtf8());
        file.write("\n");
    }

    file.close();
    return true;
}


void File::makeSaveDir() {
    if (!QDir(getSaveDir()).exists())
        QDir().mkdir(getSaveDir());
}


constStr File::getSaveDir() {
    return (QStandardPaths::writableLocation(QStandardPaths::HomeLocation))
            + "/.ministocks";  // location of all MiniStocks save and temp files
}

constStr File::getFileInSaveDir(constStr &fileName) {
    return getSaveDir() + fileName;
}

constStr File::getSaveName() {
    return getFileInSaveDir("/savedtickers");
}

constStr File::getTempFile() {
    return getFileInSaveDir("/tmp.bak");
}

constStr File::getCSVFileLocation() {
    return getFileInSaveDir("/quotes.csv");
}

constStr File::getSettingsFile() {
    return getFileInSaveDir("/settings");
}
