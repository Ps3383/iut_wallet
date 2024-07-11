/********************************************************************************
** Form generated from reading UI file 'changepass.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASS_H
#define UI_CHANGEPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changeinfo
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *changep;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *linepass;
    QLineEdit *linepassn;
    QLabel *label_3;
    QLineEdit *linepp;

    void setupUi(QDialog *changeinfo)
    {
        if (changeinfo->objectName().isEmpty())
            changeinfo->setObjectName("changeinfo");
        changeinfo->resize(791, 474);
        groupBox = new QGroupBox(changeinfo);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 30, 571, 351));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 300, 80, 24));
        changep = new QPushButton(groupBox);
        changep->setObjectName("changep");
        changep->setGeometry(QRect(440, 300, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 110, 91, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 180, 131, 31));
        linepass = new QLineEdit(groupBox);
        linepass->setObjectName("linepass");
        linepass->setGeometry(QRect(230, 120, 113, 24));
        linepassn = new QLineEdit(groupBox);
        linepassn->setObjectName("linepassn");
        linepassn->setGeometry(QRect(230, 180, 113, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 60, 61, 21));
        linepp = new QLineEdit(groupBox);
        linepp->setObjectName("linepp");
        linepp->setGeometry(QRect(230, 60, 113, 24));

        retranslateUi(changeinfo);

        QMetaObject::connectSlotsByName(changeinfo);
    } // setupUi

    void retranslateUi(QDialog *changeinfo)
    {
        changeinfo->setWindowTitle(QCoreApplication::translate("changeinfo", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("changeinfo", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("changeinfo", "back", nullptr));
        changep->setText(QCoreApplication::translate("changeinfo", "change", nullptr));
        label->setText(QCoreApplication::translate("changeinfo", "new password", nullptr));
        label_2->setText(QCoreApplication::translate("changeinfo", "re-enter new password", nullptr));
        label_3->setText(QCoreApplication::translate("changeinfo", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeinfo: public Ui_changeinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASS_H
