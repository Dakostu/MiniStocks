#include "SettingsDialog.h"
#include "ui_settingsdialog.h"
#include "FileUtils.h"
#include "Ticker.h"
#include <QDebug>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QListWidget>
#include <vector>
#include <QShortcut>
#include <QMessageBox>


SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->addTickerButton, &QPushButton::clicked, this, &SettingsDialog::addTicker);
    connect(ui->delTickerButton, &QPushButton::clicked, this, &SettingsDialog::removeTicker);
    connect(ui->okButton, &QPushButton::clicked, this, &SettingsDialog::saveAndClose);
    connect(ui->cancelButton, &QPushButton::clicked, this, &SettingsDialog::close);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));          // Ctrl+Q -> Cancel
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this, SLOT(saveAndClose()));   // Ctrl+S -> OK

    readTickers();


}

SettingsDialog& SettingsDialog::getInstance() {
    static SettingsDialog settingsDiag;
    return settingsDiag;

}

SettingsDialog::~SettingsDialog() { delete ui; }


void SettingsDialog::addTicker() {
    bool ok;

    QString ticker = QInputDialog::getText(this, tr("Add ticker"), tr("Enter ticker name"),
    QLineEdit::Normal, "", &ok);
    if (ok && !ticker.isNull()) {
        ui->savedTickList->addItem(ticker.toUpper());
    }

}

void SettingsDialog::removeTicker() { qDeleteAll(ui->savedTickList->selectedItems()); }

void SettingsDialog::readTickers() {

    std::vector<QString> savedTickers = loadFile(savename);
    for (std::vector<QString>::iterator it = savedTickers.begin(); it != savedTickers.end(); ++it)
        if (it->length())
            ui->savedTickList->addItem(*it);
}


bool SettingsDialog::saveAndClose() {

    std::vector<QString> newList;
    for (int i = 0; i < ui->savedTickList->count(); ++i) {
        newList.push_back(ui->savedTickList->item(i)->text());
    }

    if (newList.empty())
        if (!warnAboutEmptyTicker())
            return false;

    qDebug() << "Saving";
    saveFile(savename, newList);
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
            break;
        case QMessageBox::Cancel:
        default:
            emptyWarning.close();
            return 0;
            break;

    }
    return -1;
}

