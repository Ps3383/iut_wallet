/********************************************************************************
** Form generated from reading UI file 'changename.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGENAME_H
#define UI_CHANGENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changename
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *changename)
    {
        if (changename->objectName().isEmpty())
            changename->setObjectName("changename");
        changename->resize(796, 481);
        groupBox = new QGroupBox(changename);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(140, 90, 481, 281));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 70, 91, 31));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(180, 80, 113, 24));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 190, 80, 24));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 190, 80, 24));

        retranslateUi(changename);

        QMetaObject::connectSlotsByName(changename);
    } // setupUi

    void retranslateUi(QDialog *changename)
    {
        changename->setWindowTitle(QCoreApplication::translate("changename", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("changename", "change name or add name", nullptr));
        label->setText(QCoreApplication::translate("changename", "Name", nullptr));
        pushButton->setText(QCoreApplication::translate("changename", "back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("changename", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changename: public Ui_changename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGENAME_H
