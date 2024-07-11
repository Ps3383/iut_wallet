/********************************************************************************
** Form generated from reading UI file 'buy.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUY_H
#define UI_BUY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_buy
{
public:
    QFrame *frame;
    QPushButton *buy_2;
    QPushButton *back;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *linebtc;
    QLineEdit *lineeth;
    QLineEdit *linetrx;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *buy)
    {
        if (buy->objectName().isEmpty())
            buy->setObjectName("buy");
        buy->resize(793, 463);
        frame = new QFrame(buy);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(90, 30, 591, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        buy_2 = new QPushButton(frame);
        buy_2->setObjectName("buy_2");
        buy_2->setGeometry(QRect(460, 270, 80, 24));
        back = new QPushButton(frame);
        back->setObjectName("back");
        back->setGeometry(QRect(340, 270, 80, 24));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 50, 61, 41));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 110, 41, 31));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 170, 41, 41));
        linebtc = new QLineEdit(frame);
        linebtc->setObjectName("linebtc");
        linebtc->setGeometry(QRect(160, 60, 113, 24));
        lineeth = new QLineEdit(frame);
        lineeth->setObjectName("lineeth");
        lineeth->setGeometry(QRect(160, 120, 113, 24));
        linetrx = new QLineEdit(frame);
        linetrx->setObjectName("linetrx");
        linetrx->setGeometry(QRect(160, 180, 113, 24));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 250, 211, 71));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/BTC.jfif);"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(350, 20, 151, 91));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ETH.jfif);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(350, 130, 161, 91));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/TRX.jfif);"));

        retranslateUi(buy);

        QMetaObject::connectSlotsByName(buy);
    } // setupUi

    void retranslateUi(QDialog *buy)
    {
        buy->setWindowTitle(QCoreApplication::translate("buy", "Dialog", nullptr));
        buy_2->setText(QCoreApplication::translate("buy", "buy", nullptr));
        back->setText(QCoreApplication::translate("buy", "back", nullptr));
        label->setText(QCoreApplication::translate("buy", "BTC", nullptr));
        label_2->setText(QCoreApplication::translate("buy", "ETH", nullptr));
        label_3->setText(QCoreApplication::translate("buy", "TRX", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class buy: public Ui_buy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUY_H
