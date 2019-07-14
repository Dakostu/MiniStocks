#include "TickerItemUnitTest.h"
#include "../ticker/TickerItem.h"
#include <QString>

void TickerItemUnitTest::instantiateTickerItemTest() {

    TickerItem item("stock");
    QCOMPARE("STOCK", item.gettickerSymbol());
    TickerItem item2("VeryLargeCompanyName");
    QCOMPARE("VERYLARGE", item2.gettickerSymbol());

}


void TickerItemUnitTest::testCSVParsing(QString ticker, double oldPrice, double newPrice) {
    TickerItem item(ticker);
    QCOMPARE(item.gettickerSymbol(), QString(ticker).mid(0,9));
    std::vector<QString> components = {ticker, QString::number(oldPrice), QString::number(newPrice)};
    item.assignNewItemData(components);
    auto change = (newPrice - oldPrice) / newPrice;

    QString changeColor = (change < 0 ) ? "red" : "green";
    QString sign = (change >= 0) ? "+" : "";

    QCOMPARE(item.getPrice(), QString::number(newPrice, 'd', 2));
    QCOMPARE(item.getChange(), QString::number((newPrice - oldPrice) / newPrice, 'd', 2));
    QCOMPARE(item.getChangeHTMLOutput(), QString("(<font color = \"" + changeColor + "\">"
                                                 + sign + QString::number((newPrice - oldPrice) / newPrice, 'd', 2)
                                                 + "%</font>)"));

}

void TickerItemUnitTest::componentCSVParsingTestPositiveGrowth() {
    testCSVParsing(QString("ABC"), 12.5, 39.00);
}

void TickerItemUnitTest::componentCSVParsingTestNegativeGrowth() {
    testCSVParsing(QString("REALLYLONGCOMPANY"), 130.5, 129.00);
}

void TickerItemUnitTest::componentCSVParsingTestNoGrowth() {
    testCSVParsing(QString("REALLYLONGCOMPANY"), 20.05, 20.05000);
}


QTEST_MAIN(TickerItemUnitTest)
