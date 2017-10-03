#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>



namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

public:
    static SettingsDialog& getInstance();



public slots:
    void addTicker();
    void removeTicker();
    bool saveAndClose();


private:
    Ui::SettingsDialog *ui;
    void readTickers();
    int warnAboutEmptyTicker();

};

#endif // SETTINGSDIALOG_H
