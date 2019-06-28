#include "File.h"

File::File(constStr &fileName){

    this->fileName = fileName;

}



bool File::checkifFile(constStr &filename) {
    return false;
}

std::vector<QString> File::loadFile(constStr &filename) {

    return {};
}

bool File::saveFile(constStr &filename, std::vector<QString> vec) {
    return false;
}

void File::makeSaveDir() {

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
