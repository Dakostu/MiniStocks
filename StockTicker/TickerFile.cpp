#include "TickerFile.h"

TickerFile::TickerFile(constStr &fileName){

}



bool TickerFile::checkifFile(constStr &filename) {
    return false;
}

std::vector<QString> TickerFile::loadFile(constStr &filename) {

    return {};
}

bool TickerFile::saveFile(constStr &filename, std::vector<QString> vec) {
    return false;
}

void TickerFile::makeSaveDir() {

}


constStr TickerFile::getSaveDir() {
    return (QStandardPaths::writableLocation(QStandardPaths::HomeLocation))
            + "/.ministocks";  // location of all MiniStocks save and temp files
}

constStr TickerFile::getFileInSaveDir(constStr &fileName) {
    return getSaveDir() + fileName;
}

constStr TickerFile::getSaveName() {
    return getFileInSaveDir("/savedtickers");
}

constStr TickerFile::getTempFile() {
    return getFileInSaveDir("/tmp.bak");
}

constStr TickerFile::getCSVFileLocation() {
    return getFileInSaveDir("/quotes.csv");
}

constStr TickerFile::getSettingsFile() {
    return getFileInSaveDir("/settings");
}
