/********************************************************************************
** Form generated from reading UI file 'btoe.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTOE_H
#define UI_BTOE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BTOE
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *adress;
    QLineEdit *amount;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *BTOE)
    {
        if (BTOE->objectName().isEmpty())
            BTOE->setObjectName("BTOE");
        BTOE->resize(793, 467);
        groupBox = new QGroupBox(BTOE);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 60, 601, 361));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 310, 80, 24));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(470, 310, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 60, 111, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 120, 91, 41));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(240, 70, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(240, 120, 113, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 190, 161, 91));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/BTC.jfif);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 190, 181, 91));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ETH.jfif);"));

        retranslateUi(BTOE);

        QMetaObject::connectSlotsByName(BTOE);
    } // setupUi

    void retranslateUi(QDialog *BTOE)
    {
        BTOE->setWindowTitle(QCoreApplication::translate("BTOE", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BTOE", "BTC to ETH", nullptr));
        pushButton->setText(QCoreApplication::translate("BTOE", "back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("BTOE", "ok", nullptr));
        label->setText(QCoreApplication::translate("BTOE", "destination address", nullptr));
        label_2->setText(QCoreApplication::translate("BTOE", "source amount", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BTOE: public Ui_BTOE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTOE_H
