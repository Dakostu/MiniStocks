#include "TickerItemUnitTest.h"
#include "../ticker/TickerItem.h"


void TickerItemUnitTest::instantiateTickerItem() {

    TickerItem item("stock");
    QCOMPARE("STOCK", item.gettickerSymbol());
    TickerItem item2("VeryLargeCompanyName");
    QCOMPARE("VERYLARGECO", item2.gettickerSymbol());

}

QTEST_MAIN(TickerItemUnitTest)
