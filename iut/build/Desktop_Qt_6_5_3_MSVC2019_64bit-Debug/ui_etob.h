/********************************************************************************
** Form generated from reading UI file 'etob.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETOB_H
#define UI_ETOB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ETOB
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *ok;
    QLineEdit *adress;
    QLineEdit *amount;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *ETOB)
    {
        if (ETOB->objectName().isEmpty())
            ETOB->setObjectName("ETOB");
        ETOB->resize(804, 470);
        groupBox = new QGroupBox(ETOB);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 70, 601, 351));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 310, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(500, 310, 80, 24));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(230, 80, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(230, 150, 113, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 140, 111, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 70, 111, 41));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 190, 141, 111));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ETH.jfif);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 200, 141, 91));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/BTC.jfif);"));

        retranslateUi(ETOB);

        QMetaObject::connectSlotsByName(ETOB);
    } // setupUi

    void retranslateUi(QDialog *ETOB)
    {
        ETOB->setWindowTitle(QCoreApplication::translate("ETOB", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ETOB", "ETH to BTC", nullptr));
        pushButton->setText(QCoreApplication::translate("ETOB", "back", nullptr));
        ok->setText(QCoreApplication::translate("ETOB", "ok", nullptr));
        label->setText(QCoreApplication::translate("ETOB", "source amount", nullptr));
        label_2->setText(QCoreApplication::translate("ETOB", "destination address", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ETOB: public Ui_ETOB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETOB_H
