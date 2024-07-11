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

    void setupUi(QDialog *TTOB)
    {
        if (TTOB->objectName().isEmpty())
            TTOB->setObjectName("TTOB");
        TTOB->resize(789, 465);
        groupBox = new QGroupBox(TTOB);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 70, 561, 321));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 270, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(440, 270, 80, 24));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(240, 80, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(240, 150, 113, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 140, 91, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 70, 121, 41));

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
    } // retranslateUi

};

namespace Ui {
    class TTOB: public Ui_TTOB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTOB_H
