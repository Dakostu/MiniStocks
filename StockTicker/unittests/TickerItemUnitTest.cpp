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
    item.assignNewItemData(components);
    QCOMPARE(item.getPrice(), "39.00");
    QCOMPARE(item.gettickerSymbol(), "ABC");
    QCOMPARE(item.getChange(), QString::number((39 - 12.5) / 39, 'd', 2));
}


QTEST_MAIN(TickerItemUnitTest)
