/********************************************************************************
** Form generated from reading UI file 'etot.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETOT_H
#define UI_ETOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ETOT
{
public:
    QGroupBox *groupBox;
    QPushButton *back;
    QPushButton *ok;
    QLineEdit *adress;
    QLineEdit *amount;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ETOT)
    {
        if (ETOT->objectName().isEmpty())
            ETOT->setObjectName("ETOT");
        ETOT->resize(791, 474);
        groupBox = new QGroupBox(ETOT);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 70, 551, 321));
        back = new QPushButton(groupBox);
        back->setObjectName("back");
        back->setGeometry(QRect(330, 280, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(440, 280, 80, 24));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(210, 90, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(210, 160, 113, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 121, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 150, 111, 41));

        retranslateUi(ETOT);

        QMetaObject::connectSlotsByName(ETOT);
    } // setupUi

    void retranslateUi(QDialog *ETOT)
    {
        ETOT->setWindowTitle(QCoreApplication::translate("ETOT", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ETOT", "ETH to TRX", nullptr));
        back->setText(QCoreApplication::translate("ETOT", "back", nullptr));
        ok->setText(QCoreApplication::translate("ETOT", "OK", nullptr));
        label->setText(QCoreApplication::translate("ETOT", "destination address", nullptr));
        label_2->setText(QCoreApplication::translate("ETOT", "source amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ETOT: public Ui_ETOT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETOT_H
