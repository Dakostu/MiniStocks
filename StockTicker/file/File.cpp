/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the File class.
 * The File class allows easy file content loading/saving.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#include "File.h"
#include <fstream>
#include <QDir>
#include <QStandardPaths>

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
