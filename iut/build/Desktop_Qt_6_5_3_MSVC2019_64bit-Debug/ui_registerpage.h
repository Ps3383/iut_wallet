/********************************************************************************
** Form generated from reading UI file 'registerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGE_H
#define UI_REGISTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginpage
{
public:
    QPushButton *sighin_b;
    QPushButton *signup_b;

    void setupUi(QDialog *loginpage)
    {
        if (loginpage->objectName().isEmpty())
            loginpage->setObjectName("loginpage");
        loginpage->resize(787, 426);
        sighin_b = new QPushButton(loginpage);
        sighin_b->setObjectName("sighin_b");
        sighin_b->setGeometry(QRect(130, 100, 141, 51));
        signup_b = new QPushButton(loginpage);
        signup_b->setObjectName("signup_b");
        signup_b->setGeometry(QRect(330, 100, 151, 51));

        retranslateUi(loginpage);

        QMetaObject::connectSlotsByName(loginpage);
    } // setupUi

    void retranslateUi(QDialog *loginpage)
    {
        loginpage->setWindowTitle(QCoreApplication::translate("loginpage", "Dialog", nullptr));
        sighin_b->setText(QCoreApplication::translate("loginpage", "sign in", nullptr));
        signup_b->setText(QCoreApplication::translate("loginpage", "sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginpage: public Ui_loginpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGE_H
