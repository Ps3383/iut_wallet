/********************************************************************************
** Form generated from reading UI file 'createwallet.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEWALLET_H
#define UI_CREATEWALLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_createwallet
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *create;
    QPushButton *pushButton_2;

    void setupUi(QDialog *createwallet)
    {
        if (createwallet->objectName().isEmpty())
            createwallet->setObjectName("createwallet");
        createwallet->resize(799, 468);
        label = new QLabel(createwallet);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 80, 91, 41));
        lineEdit = new QLineEdit(createwallet);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 90, 113, 24));
        create = new QPushButton(createwallet);
        create->setObjectName("create");
        create->setGeometry(QRect(400, 240, 80, 24));
        pushButton_2 = new QPushButton(createwallet);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(280, 240, 80, 24));

        retranslateUi(createwallet);

        QMetaObject::connectSlotsByName(createwallet);
    } // setupUi

    void retranslateUi(QDialog *createwallet)
    {
        createwallet->setWindowTitle(QCoreApplication::translate("createwallet", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("createwallet", "wallet name", nullptr));
        create->setText(QCoreApplication::translate("createwallet", "create", nullptr));
        pushButton_2->setText(QCoreApplication::translate("createwallet", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createwallet: public Ui_createwallet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEWALLET_H
