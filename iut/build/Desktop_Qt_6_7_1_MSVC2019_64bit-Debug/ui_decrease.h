/********************************************************************************
** Form generated from reading UI file 'decrease.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECREASE_H
#define UI_DECREASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_decrease
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *decreease;
    QLabel *label;
    QLineEdit *linecoin;

    void setupUi(QDialog *decrease)
    {
        if (decrease->objectName().isEmpty())
            decrease->setObjectName("decrease");
        decrease->resize(793, 475);
        groupBox = new QGroupBox(decrease);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 50, 521, 321));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 240, 80, 24));
        decreease = new QPushButton(groupBox);
        decreease->setObjectName("decreease");
        decreease->setGeometry(QRect(350, 240, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 100, 81, 31));
        linecoin = new QLineEdit(groupBox);
        linecoin->setObjectName("linecoin");
        linecoin->setGeometry(QRect(230, 110, 113, 24));

        retranslateUi(decrease);

        QMetaObject::connectSlotsByName(decrease);
    } // setupUi

    void retranslateUi(QDialog *decrease)
    {
        decrease->setWindowTitle(QCoreApplication::translate("decrease", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("decrease", "decrease usdt", nullptr));
        pushButton->setText(QCoreApplication::translate("decrease", "back", nullptr));
        decreease->setText(QCoreApplication::translate("decrease", "decrease", nullptr));
        label->setText(QCoreApplication::translate("decrease", "coin amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class decrease: public Ui_decrease {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECREASE_H
