/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all declarations for the File class.
 * The File class allows easy file content loading/saving.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#ifndef FILE_H
#define FILE_H

#include <vector>
#include <QFile>
#include <QString>

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

    bool fileIsValid();
    std::vector<QString> loadContents();
    bool saveContentsToFile(const std::vector<QString> &vec);
    static void makeSaveDir();

    static constStr getSaveDir();
    static constStr getFileInSaveDir(constStr &fileName);
    static constStr getSaveName();
    static constStr getTempFile();
    static constStr getCSVFileLocation();
    static constStr getSettingsFile();


};

#endif
