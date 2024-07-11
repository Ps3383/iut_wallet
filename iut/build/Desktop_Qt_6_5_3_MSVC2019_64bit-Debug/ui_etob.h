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

    void setupUi(QDialog *ETOB)
    {
        if (ETOB->objectName().isEmpty())
            ETOB->setObjectName("ETOB");
        ETOB->resize(804, 470);
        groupBox = new QGroupBox(ETOB);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 70, 581, 331));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 280, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(470, 280, 80, 24));
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
    } // retranslateUi

};

namespace Ui {
    class ETOB: public Ui_ETOB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETOB_H
