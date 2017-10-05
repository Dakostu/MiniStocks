/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QAction *actiontest;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *savedTickList;
    QVBoxLayout *verticalLayout_4;
    QPushButton *addTickerButton;
    QPushButton *delTickerButton;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(254, 309);
        actiontest = new QAction(SettingsDialog);
        actiontest->setObjectName(QStringLiteral("actiontest"));
        verticalLayout_5 = new QVBoxLayout(SettingsDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        line_4 = new QFrame(SettingsDialog);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        label_2 = new QLabel(SettingsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        savedTickList = new QListWidget(SettingsDialog);
        savedTickList->setObjectName(QStringLiteral("savedTickList"));
        QFont font;
        font.setPointSize(8);
        savedTickList->setFont(font);
        savedTickList->setAutoFillBackground(false);
        savedTickList->setFrameShape(QFrame::StyledPanel);
        savedTickList->setFrameShadow(QFrame::Sunken);
        savedTickList->setLineWidth(1);
        savedTickList->setMidLineWidth(0);
        savedTickList->setDragDropMode(QAbstractItemView::InternalMove);
        savedTickList->setDefaultDropAction(Qt::MoveAction);
        savedTickList->setAlternatingRowColors(true);
        savedTickList->setSelectionMode(QAbstractItemView::MultiSelection);
        savedTickList->setProperty("isWrapping", QVariant(false));
        savedTickList->setLayoutMode(QListView::SinglePass);
        savedTickList->setViewMode(QListView::ListMode);
        savedTickList->setModelColumn(0);
        savedTickList->setUniformItemSizes(false);
        savedTickList->setWordWrap(false);
        savedTickList->setSelectionRectVisible(false);

        horizontalLayout_4->addWidget(savedTickList);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        addTickerButton = new QPushButton(SettingsDialog);
        addTickerButton->setObjectName(QStringLiteral("addTickerButton"));
        addTickerButton->setMaximumSize(QSize(30, 30));
        addTickerButton->setToolTipDuration(5);
        addTickerButton->setFlat(false);

        verticalLayout_4->addWidget(addTickerButton);

        delTickerButton = new QPushButton(SettingsDialog);
        delTickerButton->setObjectName(QStringLiteral("delTickerButton"));
        delTickerButton->setMaximumSize(QSize(30, 30));
        delTickerButton->setToolTipDuration(5);

        verticalLayout_4->addWidget(delTickerButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        line_3 = new QFrame(SettingsDialog);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okButton = new QPushButton(SettingsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setToolTipDuration(5);

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setToolTipDuration(5);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(SettingsDialog);
        QObject::connect(actiontest, SIGNAL(triggered()), SettingsDialog, SLOT(close()));

        addTickerButton->setDefault(false);
        delTickerButton->setDefault(false);
        okButton->setDefault(false);
        cancelButton->setDefault(true);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", Q_NULLPTR));
        actiontest->setText(QApplication::translate("SettingsDialog", "test", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actiontest->setShortcut(QApplication::translate("SettingsDialog", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_2->setText(QApplication::translate("SettingsDialog", "Saved Tickers", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        savedTickList->setWhatsThis(QApplication::translate("SettingsDialog", "<html><head/><body><p>This is a list containing all stock tickers to be displayed in the main window. </p><p>You can change the order by dragging items around or add/delete items using the two buttons to the right.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        addTickerButton->setToolTip(QApplication::translate("SettingsDialog", "Add a ticker", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addTickerButton->setText(QApplication::translate("SettingsDialog", "+", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        addTickerButton->setShortcut(QApplication::translate("SettingsDialog", "+", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        delTickerButton->setToolTip(QApplication::translate("SettingsDialog", "Delete selected ticker(s)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        delTickerButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        delTickerButton->setText(QApplication::translate("SettingsDialog", "-", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        delTickerButton->setShortcut(QApplication::translate("SettingsDialog", "-", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        okButton->setToolTip(QApplication::translate("SettingsDialog", "Save changes and close window", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        okButton->setText(QApplication::translate("SettingsDialog", "OK", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("SettingsDialog", "Close window without saving", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QApplication::translate("SettingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
