/********************************************************************************
** Form generated from reading UI file 'accountpage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTPAGE_H
#define UI_ACCOUNTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_accountpage
{
public:
    QPushButton *pushButton_2;
    QPushButton *createwallet;
    QPushButton *change;
    QPushButton *changeph;
    QPushButton *changea;
    QPushButton *changen;
    QPushButton *showwallet;

    void setupUi(QDialog *accountpage)
    {
        if (accountpage->objectName().isEmpty())
            accountpage->setObjectName("accountpage");
        accountpage->resize(777, 463);
        pushButton_2 = new QPushButton(accountpage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(590, 340, 101, 31));
        createwallet = new QPushButton(accountpage);
        createwallet->setObjectName("createwallet");
        createwallet->setGeometry(QRect(80, 60, 131, 41));
        change = new QPushButton(accountpage);
        change->setObjectName("change");
        change->setGeometry(QRect(320, 60, 121, 31));
        changeph = new QPushButton(accountpage);
        changeph->setObjectName("changeph");
        changeph->setGeometry(QRect(490, 60, 121, 31));
        changea = new QPushButton(accountpage);
        changea->setObjectName("changea");
        changea->setGeometry(QRect(320, 130, 121, 31));
        changen = new QPushButton(accountpage);
        changen->setObjectName("changen");
        changen->setGeometry(QRect(490, 130, 121, 31));
        showwallet = new QPushButton(accountpage);
        showwallet->setObjectName("showwallet");
        showwallet->setGeometry(QRect(80, 150, 131, 41));

        retranslateUi(accountpage);

        QMetaObject::connectSlotsByName(accountpage);
    } // setupUi

    void retranslateUi(QDialog *accountpage)
    {
        accountpage->setWindowTitle(QCoreApplication::translate("accountpage", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("accountpage", "log out", nullptr));
        createwallet->setText(QCoreApplication::translate("accountpage", "create wallet", nullptr));
        change->setText(QCoreApplication::translate("accountpage", "change passowrd", nullptr));
        changeph->setText(QCoreApplication::translate("accountpage", "change phone", nullptr));
        changea->setText(QCoreApplication::translate("accountpage", "change address", nullptr));
        changen->setText(QCoreApplication::translate("accountpage", "change name", nullptr));
        showwallet->setText(QCoreApplication::translate("accountpage", "show wallet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountpage: public Ui_accountpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTPAGE_H
