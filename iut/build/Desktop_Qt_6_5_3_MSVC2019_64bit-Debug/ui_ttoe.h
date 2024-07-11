/********************************************************************************
** Form generated from reading UI file 'ttoe.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTOE_H
#define UI_TTOE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TTOE
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *OK;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *adress;
    QLineEdit *amount;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *TTOE)
    {
        if (TTOE->objectName().isEmpty())
            TTOE->setObjectName("TTOE");
        TTOE->resize(783, 471);
        groupBox = new QGroupBox(TTOE);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 50, 561, 361));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 310, 80, 24));
        OK = new QPushButton(groupBox);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(450, 310, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 110, 131, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 50, 101, 31));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(200, 50, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(200, 120, 113, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 190, 141, 111));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/TRX.jfif);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 210, 151, 71));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ETH.jfif);"));

        retranslateUi(TTOE);

        QMetaObject::connectSlotsByName(TTOE);
    } // setupUi

    void retranslateUi(QDialog *TTOE)
    {
        TTOE->setWindowTitle(QCoreApplication::translate("TTOE", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TTOE", "TRX to ETH", nullptr));
        pushButton->setText(QCoreApplication::translate("TTOE", "back", nullptr));
        OK->setText(QCoreApplication::translate("TTOE", "OK", nullptr));
        label->setText(QCoreApplication::translate("TTOE", "source amount", nullptr));
        label_2->setText(QCoreApplication::translate("TTOE", "destination address", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TTOE: public Ui_TTOE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTOE_H
