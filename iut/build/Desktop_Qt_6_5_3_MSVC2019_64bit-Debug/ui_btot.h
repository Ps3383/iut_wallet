/********************************************************************************
** Form generated from reading UI file 'btot.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTOT_H
#define UI_BTOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BTOT
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *ok;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *adress;
    QLineEdit *amount;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *BTOT)
    {
        if (BTOT->objectName().isEmpty())
            BTOT->setObjectName("BTOT");
        BTOT->resize(806, 471);
        groupBox = new QGroupBox(BTOT);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(90, 50, 591, 361));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 310, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(470, 310, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 60, 121, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 101, 41));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(220, 70, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(220, 140, 113, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(270, 200, 191, 81));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/TRX.jfif);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 190, 151, 111));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/BTC.jfif);"));

        retranslateUi(BTOT);

        QMetaObject::connectSlotsByName(BTOT);
    } // setupUi

    void retranslateUi(QDialog *BTOT)
    {
        BTOT->setWindowTitle(QCoreApplication::translate("BTOT", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BTOT", "BTC to TRX", nullptr));
        pushButton->setText(QCoreApplication::translate("BTOT", "back", nullptr));
        ok->setText(QCoreApplication::translate("BTOT", "ok", nullptr));
        label->setText(QCoreApplication::translate("BTOT", "destination address", nullptr));
        label_2->setText(QCoreApplication::translate("BTOT", "source amount", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BTOT: public Ui_BTOT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTOT_H
