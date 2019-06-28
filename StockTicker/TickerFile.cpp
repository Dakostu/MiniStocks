#include "TickerFile.h"

TickerFile::TickerFile(constStr &fileName){

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
