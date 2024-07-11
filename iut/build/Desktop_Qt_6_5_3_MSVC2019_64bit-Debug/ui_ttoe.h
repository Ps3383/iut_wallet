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

    void setupUi(QDialog *TTOE)
    {
        if (TTOE->objectName().isEmpty())
            TTOE->setObjectName("TTOE");
        TTOE->resize(783, 471);
        groupBox = new QGroupBox(TTOE);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 40, 531, 331));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 280, 80, 24));
        OK = new QPushButton(groupBox);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(430, 280, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 160, 131, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 80, 101, 31));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(230, 90, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(230, 170, 113, 24));

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
    } // retranslateUi

};

namespace Ui {
    class TTOE: public Ui_TTOE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTOE_H
