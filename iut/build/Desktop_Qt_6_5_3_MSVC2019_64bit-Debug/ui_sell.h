/********************************************************************************
** Form generated from reading UI file 'sell.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELL_H
#define UI_SELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sell
{
public:
    QFrame *frame;
    QPushButton *back;
    QPushButton *sell_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *linebtc;
    QLineEdit *lineeth;
    QLineEdit *linetrx;

    void setupUi(QDialog *sell)
    {
        if (sell->objectName().isEmpty())
            sell->setObjectName("sell");
        sell->resize(778, 450);
        frame = new QFrame(sell);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(90, 40, 611, 351));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        back = new QPushButton(frame);
        back->setObjectName("back");
        back->setGeometry(QRect(370, 280, 80, 24));
        sell_2 = new QPushButton(frame);
        sell_2->setObjectName("sell_2");
        sell_2->setGeometry(QRect(490, 280, 80, 24));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 40, 61, 31));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 110, 61, 31));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 190, 49, 16));
        linebtc = new QLineEdit(frame);
        linebtc->setObjectName("linebtc");
        linebtc->setGeometry(QRect(180, 50, 113, 24));
        lineeth = new QLineEdit(frame);
        lineeth->setObjectName("lineeth");
        lineeth->setGeometry(QRect(180, 120, 113, 24));
        linetrx = new QLineEdit(frame);
        linetrx->setObjectName("linetrx");
        linetrx->setGeometry(QRect(180, 190, 113, 24));

        retranslateUi(sell);

        QMetaObject::connectSlotsByName(sell);
    } // setupUi

    void retranslateUi(QDialog *sell)
    {
        sell->setWindowTitle(QCoreApplication::translate("sell", "Dialog", nullptr));
        back->setText(QCoreApplication::translate("sell", "back", nullptr));
        sell_2->setText(QCoreApplication::translate("sell", "sell", nullptr));
        label->setText(QCoreApplication::translate("sell", "BTC", nullptr));
        label_2->setText(QCoreApplication::translate("sell", "ETH", nullptr));
        label_3->setText(QCoreApplication::translate("sell", "TRX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sell: public Ui_sell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELL_H
