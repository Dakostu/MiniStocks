#include "File.h"
#include <fstream>
#include <QDir>

File::File(constStr &fileName){
    this->fileName = fileName;
    QFile file(this->fileName);
}


bool File::checkifFile(constStr &filename) {
    QFile file(filename);
    return (file.exists() && file.size() && !file.error());
}


std::vector<QString> File::loadContents() {
    std::vector<QString> tickVec;
    file.open(QIODevice::ReadOnly);

    while (!file.atEnd())
        tickVec.push_back(file.readLine().trimmed()); // trimmed(): Remove linebreak

    file.reset();
    return tickVec;
}


bool File::saveFile(constStr &filename, std::vector<QString> vec) {
    makeSaveDir();

    std::ofstream save(filename.toStdString());

    for (std::vector<QString>::iterator it = vec.begin(); it != vec.end(); ++it)
        save << it->toStdString()<< "\n";

    save.close();
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
