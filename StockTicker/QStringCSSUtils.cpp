/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "QStringCSSUtils.h"
#include <QStringList>
#include <math.h>

constStr quotMark("\"");
constStr tab("\t");


QString removeStringToken (constStr &message, constStr &token) {
    QStringList splitted = message.split(token);
    return splitted.value( splitted.length() - 2 );
}

double stringIntoDoubleRounded (QString percentage) {
    return round(removeStringToken(percentage,"%").toDouble()*100)/100;
}

// these two are obvious (for graphical output purposes)
QString buildColorblock (constStr &color){
    return "<font color = \"" + color + "\">";
}

QString colorizeText (constStr &message, constStr &color) {
    return buildColorblock(color) + message + "</font>";
}





