#include "MainWindow.h"
#include "TickerRefreshThread.h"
#include <QApplication>
#include <QCoreApplication>
#include <QThread>
#include <QObject>
using namespace std;

int main(int argc, char *argv[]) {

     QApplication a(argc, argv);
     MainWindow w;
     w.show();

     //a.setQuitOnLastWindowClosed(true);
     QObject::connect(&w, SIGNAL(exitProg()),&a,SLOT(quit()));



     return a.exec();
}
