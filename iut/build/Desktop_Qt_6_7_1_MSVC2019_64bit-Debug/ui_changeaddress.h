/********************************************************************************
** Form generated from reading UI file 'changeaddress.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEADDRESS_H
#define UI_CHANGEADDRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changeaddress
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *backkk;
    QPushButton *adddd;

    void setupUi(QDialog *changeaddress)
    {
        if (changeaddress->objectName().isEmpty())
            changeaddress->setObjectName("changeaddress");
        changeaddress->resize(774, 462);
        groupBox = new QGroupBox(changeaddress);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 50, 561, 311));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 60, 91, 41));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 70, 113, 24));
        backkk = new QPushButton(groupBox);
        backkk->setObjectName("backkk");
        backkk->setGeometry(QRect(120, 180, 80, 24));
        adddd = new QPushButton(groupBox);
        adddd->setObjectName("adddd");
        adddd->setGeometry(QRect(260, 180, 80, 24));

        retranslateUi(changeaddress);

        QMetaObject::connectSlotsByName(changeaddress);
    } // setupUi

    void retranslateUi(QDialog *changeaddress)
    {
        changeaddress->setWindowTitle(QCoreApplication::translate("changeaddress", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("changeaddress", "change or add address", nullptr));
        label->setText(QCoreApplication::translate("changeaddress", "Address", nullptr));
        backkk->setText(QCoreApplication::translate("changeaddress", "back", nullptr));
        adddd->setText(QCoreApplication::translate("changeaddress", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeaddress: public Ui_changeaddress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEADDRESS_H
