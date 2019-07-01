/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the Settings dialog.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */


#include "../file/File.h"
#include "SettingsDialog.h"
#include "ui_settingsdialog.h"
#include "../ticker/Ticker.h"
#include <QDebug>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QListWidget>
#include <QShortcut>
#include <QMessageBox>
#include <vector>


SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->addTickerButton, &QPushButton::clicked, this, &SettingsDialog::addTicker);
    connect(ui->delTickerButton, &QPushButton::clicked, this, &SettingsDialog::removeTicker);
    connect(ui->okButton, &QPushButton::clicked, this, &SettingsDialog::saveAndClose);
    connect(ui->cancelButton, &QPushButton::clicked, this, &SettingsDialog::close);

    // Ctrl+Q -> Cancel, Ctrl-S -> OK
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this, SLOT(saveAndClose()));

    readTickers();

}

SettingsDialog::~SettingsDialog() {
    delete ui;
}

// Add ticker symbol to QList of ticker symbols
void SettingsDialog::addTicker() {
    bool ok;

    QString ticker = QInputDialog::getText(this, tr("Add ticker"), tr("Enter ticker name\n"),
    QLineEdit::Normal, "", &ok);
    if (ok && !ticker.isNull()) {
        ui->savedTickList->addItem(ticker.toUpper());
    }

}

// removes all selected QList ticker symbols
void SettingsDialog::removeTicker() { qDeleteAll(ui->savedTickList->selectedItems()); }


// read ticker symbols from savefile into QList
void SettingsDialog::readTickers() {
    File saveFile(File::getSaveName());

    auto savedTickers = saveFile.loadContents();
    for (auto ticker : savedTickers)
        ui->savedTickList->addItem(ticker);
}

// Save QList into savefile and close window
bool SettingsDialog::saveAndClose() {

    if (ui->savedTickList->count() == 0     // If an empty list is saved..
            && !warnAboutEmptyTicker()) {   // and user clicked Cancel on warning window...
        readTickers();                      // -> load previously saved tickers
        return false;                       // -> do not save and close warning window
    }

    std::vector<QString> newList;
    for (int i = 0; i < ui->savedTickList->count(); ++i)
        newList.push_back(ui->savedTickList->item(i)->text());

    qDebug() << "Saving";

    File saveFile(File::getSaveName());
    saveFile.saveContentsToFile(newList);
    return this->close();

}

// Warning message box if all tickers are deleted in saved list
// Return value is confirmation that defaults will be restored
int SettingsDialog::warnAboutEmptyTicker() {
    QMessageBox emptyWarning;
    emptyWarning.setWindowTitle("Attention!");
    emptyWarning.setText("Saving an empty ticker list will restore the default ticker list.");
    emptyWarning.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    emptyWarning.setDefaultButton(QMessageBox::Cancel);
    int ret = emptyWarning.exec();
    switch (ret) {
        case QMessageBox::Ok:
            emptyWarning.close();
            return 1;
        case QMessageBox::Cancel:
        default:
            emptyWarning.close();
            return 0;

    }
    return -1;
}

