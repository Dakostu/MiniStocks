/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    static About& getInstance();


private:
    Ui::About *ui;
    explicit About(QWidget *parent = 0);
    ~About();
};

#endif // ABOUT_H
