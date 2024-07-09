/********************************************************************************
** Form generated from reading UI file 'changeinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFO_H
#define UI_CHANGEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changeinfo
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

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
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 300, 80, 24));

        retranslateUi(changeinfo);

        QMetaObject::connectSlotsByName(changeinfo);
    } // setupUi

    void retranslateUi(QDialog *changeinfo)
    {
        changeinfo->setWindowTitle(QCoreApplication::translate("changeinfo", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("changeinfo", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("changeinfo", "back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("changeinfo", "change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeinfo: public Ui_changeinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFO_H
