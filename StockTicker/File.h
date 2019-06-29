#ifndef FILE_H
#define FILE_H

#include <vector>
#include <QFile>
#include <QString>
#include <QStandardPaths>

using constStr = const QString;

class File
{
protected:

    QString fileName;
    QFile file;
    std::vector<QString> fileContent;


public:

    File(constStr &fileName);
    ~File();

    bool checkifFile(constStr &filename);

    std::vector<QString> loadContents();
    bool saveContentsToFile(const std::vector<QString> &vec);
    void makeSaveDir();

    static constStr getSaveDir();
    static constStr getFileInSaveDir(constStr &fileName);
    static constStr getSaveName();
    static constStr getTempFile();
    static constStr getCSVFileLocation();
    static constStr getSettingsFile();


};

#endif
