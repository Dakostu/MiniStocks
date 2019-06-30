/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all declarations for the About window.
 *
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
    explicit About(QWidget *parent = nullptr);
    ~About();



private:
    Ui::About *ui;

};

#endif // ABOUT_H
