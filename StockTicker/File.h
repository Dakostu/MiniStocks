#ifndef FILE_H
#define FILE_H

#include <vector>
#include <QString>
#include <QStandardPaths>

using constStr = const QString;

class File
{

    QString fileName;

public:


    File(constStr &fileName);

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
