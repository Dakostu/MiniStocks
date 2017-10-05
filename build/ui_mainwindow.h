/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *symbolColumn;
    QSpacerItem *spacer1;
    QLabel *priceColumn;
    QSpacerItem *spacer2;
    QLabel *curColumn;
    QSpacerItem *spacer3;
    QLabel *changColumn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(134, 42);
        MainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setStyleSheet(QStringLiteral("background-color:white"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("background-color:black\n"
""));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        symbolColumn = new QLabel(frame);
        symbolColumn->setObjectName(QStringLiteral("symbolColumn"));
        symbolColumn->setEnabled(false);
        symbolColumn->setStyleSheet(QStringLiteral("color:lightgray"));

        horizontalLayout->addWidget(symbolColumn);

        spacer1 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer1);

        priceColumn = new QLabel(frame);
        priceColumn->setObjectName(QStringLiteral("priceColumn"));
        priceColumn->setEnabled(false);
        priceColumn->setStyleSheet(QStringLiteral("color:lightgray"));
        priceColumn->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        priceColumn->setMargin(0);
        priceColumn->setIndent(3);

        horizontalLayout->addWidget(priceColumn);

        spacer2 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer2);

        curColumn = new QLabel(frame);
        curColumn->setObjectName(QStringLiteral("curColumn"));
        curColumn->setEnabled(false);
        curColumn->setStyleSheet(QStringLiteral("color:lightgray"));
        curColumn->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        curColumn->setIndent(6);

        horizontalLayout->addWidget(curColumn);

        spacer3 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer3);

        changColumn = new QLabel(frame);
        changColumn->setObjectName(QStringLiteral("changColumn"));
        changColumn->setEnabled(false);
        changColumn->setStyleSheet(QStringLiteral("color:lightgray"));
        changColumn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(changColumn);

        symbolColumn->raise();
        priceColumn->raise();
        curColumn->raise();
        changColumn->raise();

        verticalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MiniStocks", Q_NULLPTR));
        symbolColumn->setText(QApplication::translate("MainWindow", "s", Q_NULLPTR));
        priceColumn->setText(QApplication::translate("MainWindow", "p", Q_NULLPTR));
        curColumn->setText(QApplication::translate("MainWindow", "c", Q_NULLPTR));
        changColumn->setText(QApplication::translate("MainWindow", "ch", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
