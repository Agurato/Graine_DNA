/********************************************************************************
** Form generated from reading UI file 'fencalc.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCALC_H
#define UI_FENCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenCalc
{
public:
    QWidget *centralwidget;
    QSpinBox *num2;
    QPushButton *equalsButton;
    QLabel *result;
    QSpinBox *num1;
    QComboBox *operations;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FenCalc)
    {
        if (FenCalc->objectName().isEmpty())
            FenCalc->setObjectName(QStringLiteral("FenCalc"));
        FenCalc->resize(505, 122);
        centralwidget = new QWidget(FenCalc);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        num2 = new QSpinBox(centralwidget);
        num2->setObjectName(QStringLiteral("num2"));
        num2->setGeometry(QRect(210, 20, 61, 33));
        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName(QStringLiteral("equalsButton"));
        equalsButton->setGeometry(QRect(300, 20, 96, 31));
        result = new QLabel(centralwidget);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(410, 20, 65, 21));
        num1 = new QSpinBox(centralwidget);
        num1->setObjectName(QStringLiteral("num1"));
        num1->setGeometry(QRect(30, 20, 61, 33));
        operations = new QComboBox(centralwidget);
        operations->setObjectName(QStringLiteral("operations"));
        operations->setGeometry(QRect(110, 20, 76, 29));
        FenCalc->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FenCalc);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 505, 27));
        FenCalc->setMenuBar(menubar);
        statusbar = new QStatusBar(FenCalc);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FenCalc->setStatusBar(statusbar);

        retranslateUi(FenCalc);

        QMetaObject::connectSlotsByName(FenCalc);
    } // setupUi

    void retranslateUi(QMainWindow *FenCalc)
    {
        FenCalc->setWindowTitle(QApplication::translate("FenCalc", "MainWindow", 0));
        equalsButton->setText(QApplication::translate("FenCalc", "=", 0));
        result->setText(QApplication::translate("FenCalc", "0", 0));
        operations->clear();
        operations->insertItems(0, QStringList()
         << QApplication::translate("FenCalc", "+", 0)
         << QApplication::translate("FenCalc", "-", 0)
         << QApplication::translate("FenCalc", "*", 0)
         << QApplication::translate("FenCalc", "/", 0)
         << QApplication::translate("FenCalc", "%", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class FenCalc: public Ui_FenCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCALC_H
