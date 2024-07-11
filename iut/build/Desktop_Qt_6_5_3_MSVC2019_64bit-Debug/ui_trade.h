/********************************************************************************
** Form generated from reading UI file 'trade.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADE_H
#define UI_TRADE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_trade
{
public:
    QGroupBox *groupBox;
    QPushButton *back;
    QPushButton *BtoE;
    QPushButton *BtoT;
    QPushButton *EtoT;
    QPushButton *TtoB;
    QPushButton *EtoB;
    QPushButton *TtoE;

    void setupUi(QDialog *trade)
    {
        if (trade->objectName().isEmpty())
            trade->setObjectName("trade");
        trade->resize(791, 468);
        groupBox = new QGroupBox(trade);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(120, 50, 501, 341));
        back = new QPushButton(groupBox);
        back->setObjectName("back");
        back->setGeometry(QRect(380, 280, 80, 24));
        BtoE = new QPushButton(groupBox);
        BtoE->setObjectName("BtoE");
        BtoE->setGeometry(QRect(40, 60, 121, 51));
        BtoT = new QPushButton(groupBox);
        BtoT->setObjectName("BtoT");
        BtoT->setGeometry(QRect(190, 60, 131, 51));
        EtoT = new QPushButton(groupBox);
        EtoT->setObjectName("EtoT");
        EtoT->setGeometry(QRect(40, 130, 121, 51));
        TtoB = new QPushButton(groupBox);
        TtoB->setObjectName("TtoB");
        TtoB->setGeometry(QRect(40, 210, 121, 51));
        EtoB = new QPushButton(groupBox);
        EtoB->setObjectName("EtoB");
        EtoB->setGeometry(QRect(190, 130, 131, 51));
        TtoE = new QPushButton(groupBox);
        TtoE->setObjectName("TtoE");
        TtoE->setGeometry(QRect(190, 210, 131, 51));

        retranslateUi(trade);

        QMetaObject::connectSlotsByName(trade);
    } // setupUi

    void retranslateUi(QDialog *trade)
    {
        trade->setWindowTitle(QCoreApplication::translate("trade", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("trade", "Trade", nullptr));
        back->setText(QCoreApplication::translate("trade", "back", nullptr));
        BtoE->setText(QCoreApplication::translate("trade", "from BTC to ETH", nullptr));
        BtoT->setText(QCoreApplication::translate("trade", "from BTC to TRX", nullptr));
        EtoT->setText(QCoreApplication::translate("trade", "from ETH to TRX", nullptr));
        TtoB->setText(QCoreApplication::translate("trade", "from TRX to BTC", nullptr));
        EtoB->setText(QCoreApplication::translate("trade", "from ETH to BTC", nullptr));
        TtoE->setText(QCoreApplication::translate("trade", "from TRX to ETH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trade: public Ui_trade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADE_H
