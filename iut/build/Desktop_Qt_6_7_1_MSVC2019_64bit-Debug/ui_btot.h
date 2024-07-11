/********************************************************************************
** Form generated from reading UI file 'btot.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
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

    void setupUi(QDialog *BTOT)
    {
        if (BTOT->objectName().isEmpty())
            BTOT->setObjectName("BTOT");
        BTOT->resize(806, 471);
        groupBox = new QGroupBox(BTOT);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 70, 531, 321));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 270, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(400, 270, 80, 24));
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
    } // retranslateUi

};

namespace Ui {
    class BTOT: public Ui_BTOT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTOT_H
