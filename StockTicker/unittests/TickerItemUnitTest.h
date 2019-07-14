#include <QtTest/QtTest>

class TickerItemUnitTest : public QObject {
    Q_OBJECT
private:
    void testCSVParsing (QString ticker, double change, double price);
private slots:
    void instantiateTickerItemTest();
    void componentCSVParsingTestPositiveGrowth();
    void componentCSVParsingTestNegativeGrowth();
};
