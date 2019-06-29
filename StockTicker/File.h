#ifndef FILE_H
#define FILE_H

#include <vector>
#include <QFile>
#include <QString>
#include <QStandardPaths>

using constStr = const QString;

class File
{

    QString fileName;
    QFile file;
    std::vector<QString> fileContent;

    ~File();

public:

    File(constStr &fileName);

    bool checkifFile(constStr &filename);

    std::vector<QString> loadContents();
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
