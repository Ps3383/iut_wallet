/********************************************************************************
** Form generated from reading UI file 'showwallet.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWALLET_H
#define UI_SHOWWALLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_showwallet
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *linewalletname;
    QPushButton *pushButton;
    QPushButton *shw;
    QTextBrowser *textBrowser;
    QPushButton *buy;
    QPushButton *increase;
    QPushButton *sell;
    QPushButton *decrease;

    void setupUi(QDialog *showwallet)
    {
        if (showwallet->objectName().isEmpty())
            showwallet->setObjectName("showwallet");
        showwallet->resize(793, 476);
        groupBox = new QGroupBox(showwallet);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 30, 691, 401));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 91, 21));
        linewalletname = new QLineEdit(groupBox);
        linewalletname->setObjectName("linewalletname");
        linewalletname->setGeometry(QRect(190, 80, 113, 24));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 180, 80, 24));
        shw = new QPushButton(groupBox);
        shw->setObjectName("shw");
        shw->setGeometry(QRect(220, 180, 80, 24));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(350, 40, 311, 341));
        buy = new QPushButton(groupBox);
        buy->setObjectName("buy");
        buy->setGeometry(QRect(80, 240, 80, 24));
        increase = new QPushButton(groupBox);
        increase->setObjectName("increase");
        increase->setGeometry(QRect(220, 240, 80, 24));
        sell = new QPushButton(groupBox);
        sell->setObjectName("sell");
        sell->setGeometry(QRect(80, 300, 80, 24));
        decrease = new QPushButton(groupBox);
        decrease->setObjectName("decrease");
        decrease->setGeometry(QRect(220, 300, 80, 24));

        retranslateUi(showwallet);

        QMetaObject::connectSlotsByName(showwallet);
    } // setupUi

    void retranslateUi(QDialog *showwallet)
    {
        showwallet->setWindowTitle(QCoreApplication::translate("showwallet", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("showwallet", "show wallet", nullptr));
        label->setText(QCoreApplication::translate("showwallet", "wallet name", nullptr));
        pushButton->setText(QCoreApplication::translate("showwallet", "back", nullptr));
        shw->setText(QCoreApplication::translate("showwallet", "show", nullptr));
        buy->setText(QCoreApplication::translate("showwallet", "buy", nullptr));
        increase->setText(QCoreApplication::translate("showwallet", "increase", nullptr));
        sell->setText(QCoreApplication::translate("showwallet", "sell", nullptr));
        decrease->setText(QCoreApplication::translate("showwallet", "decrease", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showwallet: public Ui_showwallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWALLET_H
