#ifndef TICKERITEM_H
#define TICKERITEM_H

#include <QString>
#include <vector>

class TickerItem {

    QString tickerSymbol;
    double value;
    QString currency;
    double change;
    std::vector<QString> parsedCSV;


    void assignComponents(std::vector<QString> &parsedCSV);

public:
    TickerItem(QString symbol);
    QString toString();
    QString gettickerSymbol();
    QString getPrice();
    QString getCurrency();
    QString getChange();
    void loadItemData();

};


#endif
