#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../ticker/TickerItem.h"
#include "../ticker/TickerInfoDownloader.h"



TEST_CASE("TickerItem is properly instantiated", "[TickerItem]") {

    TickerItem item("stock");
    REQUIRE(item.gettickerSymbol() == "STOCK");
    TickerItem item2("ImportantCompany");
    REQUIRE(item.gettickerSymbol() == "IMPORTANTCO");

}
