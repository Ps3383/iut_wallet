/********************************************************************************
** Form generated from reading UI file 'increase.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCREASE_H
#define UI_INCREASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_increase
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *increase_2;
    QLabel *label;
    QLineEdit *linecoin;

    void setupUi(QDialog *increase)
    {
        if (increase->objectName().isEmpty())
            increase->setObjectName("increase");
        increase->resize(795, 470);
        groupBox = new QGroupBox(increase);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 40, 561, 351));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 270, 80, 24));
        increase_2 = new QPushButton(groupBox);
        increase_2->setObjectName("increase_2");
        increase_2->setGeometry(QRect(390, 270, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 101, 31));
        linecoin = new QLineEdit(groupBox);
        linecoin->setObjectName("linecoin");
        linecoin->setGeometry(QRect(210, 100, 113, 24));

        retranslateUi(increase);

        QMetaObject::connectSlotsByName(increase);
    } // setupUi

    void retranslateUi(QDialog *increase)
    {
        increase->setWindowTitle(QCoreApplication::translate("increase", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("increase", "increase usdt", nullptr));
        pushButton->setText(QCoreApplication::translate("increase", "back", nullptr));
        increase_2->setText(QCoreApplication::translate("increase", "increase", nullptr));
        label->setText(QCoreApplication::translate("increase", "coin amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class increase: public Ui_increase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCREASE_H
