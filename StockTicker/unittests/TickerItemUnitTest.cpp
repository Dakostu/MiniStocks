#include "TickerItemUnitTest.h"
#include "../ticker/TickerItem.h"
#include <QString>

void TickerItemUnitTest::instantiateTickerItemTest() {

    TickerItem item("stock");
    QCOMPARE("STOCK", item.gettickerSymbol());
    TickerItem item2("VeryLargeCompanyName");
    QCOMPARE("VERYLARGE", item2.gettickerSymbol());

}


void TickerItemUnitTest::componentCSVParsingTest() {

    TickerItem item("ABC");
    std::vector<QString> components = {"ABC", "+12.5", "39.00"};
    // make component parsing more testable


}


QTEST_MAIN(TickerItemUnitTest)
