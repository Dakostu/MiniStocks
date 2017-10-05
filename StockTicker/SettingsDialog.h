/*
 * MiniStocks created by Daniel Kostuj, 2017
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

    Ui::SettingsDialog *ui;

    void readTickers();
    int warnAboutEmptyTicker();

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();



public slots:
    void addTicker();
    void removeTicker();
    bool saveAndClose();




};

#endif // SETTINGSDIALOG_H
