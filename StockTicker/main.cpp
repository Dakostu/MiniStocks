/*
 * MiniStocks created by Daniel Kostuj
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "dialogs/MainWindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QThread>
#include <QObject>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {

     QApplication a(argc, argv);
     MainWindow w;
     w.show();

     QObject::connect(&w, SIGNAL(exitProg()),&a,SLOT(quit()));

     return a.exec();
}
