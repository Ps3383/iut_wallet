/********************************************************************************
** Form generated from reading UI file 'changephone.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPHONE_H
#define UI_CHANGEPHONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changephone
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *backk;
    QPushButton *addd;

    void setupUi(QDialog *changephone)
    {
        if (changephone->objectName().isEmpty())
            changephone->setObjectName("changephone");
        changephone->resize(777, 472);
        groupBox = new QGroupBox(changephone);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 80, 461, 301));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 70, 91, 31));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 80, 113, 24));
        backk = new QPushButton(groupBox);
        backk->setObjectName("backk");
        backk->setGeometry(QRect(110, 180, 80, 24));
        addd = new QPushButton(groupBox);
        addd->setObjectName("addd");
        addd->setGeometry(QRect(250, 180, 80, 24));

        retranslateUi(changephone);

        QMetaObject::connectSlotsByName(changephone);
    } // setupUi

    void retranslateUi(QDialog *changephone)
    {
        changephone->setWindowTitle(QCoreApplication::translate("changephone", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("changephone", "change or add phone number", nullptr));
        label->setText(QCoreApplication::translate("changephone", "phone number", nullptr));
        backk->setText(QCoreApplication::translate("changephone", "back", nullptr));
        addd->setText(QCoreApplication::translate("changephone", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changephone: public Ui_changephone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPHONE_H
