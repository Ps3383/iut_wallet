/********************************************************************************
** Form generated from reading UI file 'signinpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINPAGE_H
#define UI_SIGNINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signinpage
{
public:
    QGroupBox *groupBox;
    QPushButton *login;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineemail;
    QLineEdit *linepassword;

    void setupUi(QDialog *signinpage)
    {
        if (signinpage->objectName().isEmpty())
            signinpage->setObjectName("signinpage");
        signinpage->resize(795, 420);
        groupBox = new QGroupBox(signinpage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 20, 491, 331));
        login = new QPushButton(groupBox);
        login->setObjectName("login");
        login->setGeometry(QRect(390, 280, 80, 24));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(260, 280, 80, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 50, 61, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 110, 61, 31));
        lineemail = new QLineEdit(groupBox);
        lineemail->setObjectName("lineemail");
        lineemail->setGeometry(QRect(150, 60, 113, 24));
        linepassword = new QLineEdit(groupBox);
        linepassword->setObjectName("linepassword");
        linepassword->setGeometry(QRect(150, 110, 113, 24));

        retranslateUi(signinpage);

        QMetaObject::connectSlotsByName(signinpage);
    } // setupUi

    void retranslateUi(QDialog *signinpage)
    {
        signinpage->setWindowTitle(QCoreApplication::translate("signinpage", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("signinpage", "sign in", nullptr));
        login->setText(QCoreApplication::translate("signinpage", "login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("signinpage", "back", nullptr));
        label->setText(QCoreApplication::translate("signinpage", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("signinpage", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signinpage: public Ui_signinpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINPAGE_H
