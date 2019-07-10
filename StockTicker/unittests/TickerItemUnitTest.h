#include <QtTest/QtTest>

class TickerItemUnitTest : public QObject {
    Q_OBJECT
private slots:
    void instantiateTickerItemTest();
    void componentCSVParsingTest();
};
