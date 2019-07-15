#define CATCH_CONFIG_MAIN

#include "../ticker/TickerItem.h"
#include "catch.hpp"


TEST_CASE( "A ticker item is properly instantiated", "[TickerItem]" ) {
    TickerItem item("stock");
    REQUIRE(item.gettickerSymbol() == "STOCK");
    TickerItem item2("VeryLargeCompanyName");
    REQUIRE(item2.gettickerSymbol() == "VERYLARGE");
}


void testCSVParsing(QString ticker, double oldPrice, double newPrice) {
    TickerItem item(ticker);
    REQUIRE(item.gettickerSymbol() == QString(ticker).mid(0,9));
    std::vector<QString> components = {ticker, QString::number(oldPrice), QString::number(newPrice)};
    item.assignNewItemData(components);
    auto change = (newPrice - oldPrice) / newPrice;

    QString changeColor = (change < 0 ) ? "red" : "green";
    QString sign = (change >= 0) ? "+" : "";

    REQUIRE(item.getPrice() == QString::number(newPrice, 'd', 2));
    REQUIRE(item.getChange() == QString::number((newPrice - oldPrice) / newPrice, 'd', 2));
    REQUIRE(item.getChangeHTMLOutput() == QString("(<font color = \"" + changeColor + "\">"
                                                 + sign + QString::number((newPrice - oldPrice) / newPrice, 'd', 2)
                                                 + "%</font>)"));

}

TEST_CASE( "Positive stock growth is properly parsed", "[TickerItem]" ) {
    testCSVParsing(QString("ABC"), 12.5, 39.00);
}

TEST_CASE( "Negative stock growth is properly parsed", "[TickerItem]" ) {
    testCSVParsing(QString("REALLYLONGCOMPANY"), 130.5, 129.00);
}

TEST_CASE( "No stock growth is properly parsed", "[TickerItem]" ) {
    testCSVParsing(QString("REALLYLONGCOMPANY"), 20.05, 20.05000);
}
