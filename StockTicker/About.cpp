#include "About.h"
#include "ui_about.h"
#include <QShortcut>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close())); // Ctrl+Q -> OK
}

About::~About()
{
    delete ui;
}

About& About::getInstance() {
    static About aboutWindow;
    return aboutWindow;

}
