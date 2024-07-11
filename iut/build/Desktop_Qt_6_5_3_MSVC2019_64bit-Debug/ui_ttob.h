/********************************************************************************
** Form generated from reading UI file 'ttob.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTOB_H
#define UI_TTOB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TTOB
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

    void setupUi(QDialog *TTOB)
    {
        if (TTOB->objectName().isEmpty())
            TTOB->setObjectName("TTOB");
        TTOB->resize(789, 465);
        groupBox = new QGroupBox(TTOB);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 70, 621, 351));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 300, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(510, 300, 80, 24));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(210, 60, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(210, 130, 113, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 120, 91, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 50, 121, 41));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 200, 161, 81));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/TRX.jfif);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(270, 200, 141, 81));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/BTC.jfif);"));

        retranslateUi(TTOB);

        QMetaObject::connectSlotsByName(TTOB);
    } // setupUi

    void retranslateUi(QDialog *TTOB)
    {
        TTOB->setWindowTitle(QCoreApplication::translate("TTOB", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TTOB", "TRX to BTC", nullptr));
        pushButton->setText(QCoreApplication::translate("TTOB", "back", nullptr));
        ok->setText(QCoreApplication::translate("TTOB", "ok", nullptr));
        label->setText(QCoreApplication::translate("TTOB", "source_amount", nullptr));
        label_2->setText(QCoreApplication::translate("TTOB", "destination address", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TTOB: public Ui_TTOB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTOB_H
