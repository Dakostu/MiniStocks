#ifndef TICKER_FILE_H
#define TICKER_FILE_H

#include <vector>
#include <QString>
#include <QStandardPaths>

using constStr = const QString;

class TickerFile
{
public:


    TickerFile(constStr &fileName);

    bool checkifFile(constStr &filename);
    std::vector<QString> loadFile(constStr &filename);
    bool saveFile(constStr &filename, std::vector<QString> vec);
    void makeSaveDir();

    static constStr getSaveDir();
    static constStr getFileInSaveDir(constStr &fileName);
    static constStr getSaveName();
    static constStr getTempFile();
    static constStr getCSVFileLocation();
    static constStr getSettingsFile();


};

#endif
