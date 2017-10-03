#ifndef QSTRINGCSSUTILS_H
#define QSTRINGCSSUTILS_H

#include <QString>

typedef const QString constStr;

extern constStr quotMark;
extern constStr tab;

QString removeStringToken (constStr &message, constStr &token);
QString buildColorblock (constStr &color);
QString colorizeText (constStr &message, constStr &color);
double stringIntoDoubleRounded(QString percentage);

#endif // QSTRINGCSSUTILS_H
