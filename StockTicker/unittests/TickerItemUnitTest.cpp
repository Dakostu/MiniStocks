#include "TickerItemUnitTest.h"
#include "../ticker/TickerItem.h"
#include <QString>

void TickerItemUnitTest::instantiateTickerItemTest() {

    TickerItem item("stock");
    QCOMPARE("STOCK", item.gettickerSymbol());
    TickerItem item2("VeryLargeCompanyName");
    QCOMPARE("VERYLARGE", item2.gettickerSymbol());

}


void TickerItemUnitTest::testCSVParsing(QString ticker, double change, double price) {
    TickerItem item(ticker);
    QCOMPARE(item.gettickerSymbol(), QString(ticker).mid(0,9));
    std::vector<QString> components = {ticker, QString::number(change), QString::number(price)};
    item.assignNewItemData(components);
    QString changeColor = (change < 0 ) ? "red" : "green";
    QString sign = (change >= 0) ? "+" : "";

    QCOMPARE(item.getPrice(), QString::number(price, 'd', 2));
    QCOMPARE(item.getChange(), QString::number((price - change) / price, 'd', 2));
    QCOMPARE(item.getChangeHTMLOutput(), QString("(<font color = \"" + changeColor + "\">"
                                                 + sign + QString::number((price - change) / price, 'd', 2)
                                                 + "%</font>)"));

}

void TickerItemUnitTest::componentCSVParsingTestPositiveGrowth() {
    testCSVParsing(QString("ABC"), 12.5, 39.00);
}

void TickerItemUnitTest::componentCSVParsingTestNegativeGrowth() {
    testCSVParsing(QString("REALLYLONGCOMPANY"), -12.5, 129.00);
}


QTEST_MAIN(TickerItemUnitTest)
