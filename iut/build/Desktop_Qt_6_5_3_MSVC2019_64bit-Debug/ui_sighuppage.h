/********************************************************************************
** Form generated from reading UI file 'sighuppage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGHUPPAGE_H
#define UI_SIGHUPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sighuppage
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineemail;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *linepassword;
    QLineEdit *linename;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineaddress;
    QLabel *label_5;
    QLineEdit *linetele;
    QPushButton *regi;
    QPushButton *pushButton_2;
    QLabel *label_6;

    void setupUi(QDialog *sighuppage)
    {
        if (sighuppage->objectName().isEmpty())
            sighuppage->setObjectName("sighuppage");
        sighuppage->resize(748, 420);
        groupBox = new QGroupBox(sighuppage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 10, 581, 371));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        lineemail = new QLineEdit(groupBox);
        lineemail->setObjectName("lineemail");
        lineemail->setGeometry(QRect(210, 40, 113, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 40, 61, 21));
        label->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 90, 61, 21));
        linepassword = new QLineEdit(groupBox);
        linepassword->setObjectName("linepassword");
        linepassword->setGeometry(QRect(210, 90, 113, 24));
        linename = new QLineEdit(groupBox);
        linename->setObjectName("linename");
        linename->setGeometry(QRect(210, 140, 113, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 140, 61, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 200, 61, 21));
        lineaddress = new QLineEdit(groupBox);
        lineaddress->setObjectName("lineaddress");
        lineaddress->setGeometry(QRect(210, 200, 113, 24));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 260, 71, 21));
        linetele = new QLineEdit(groupBox);
        linetele->setObjectName("linetele");
        linetele->setGeometry(QRect(210, 260, 113, 24));
        regi = new QPushButton(groupBox);
        regi->setObjectName("regi");
        regi->setGeometry(QRect(470, 320, 80, 24));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 320, 80, 24));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(370, 30, 191, 261));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/lllll.jpg);"));

        retranslateUi(sighuppage);

        QMetaObject::connectSlotsByName(sighuppage);
    } // setupUi

    void retranslateUi(QDialog *sighuppage)
    {
        sighuppage->setWindowTitle(QCoreApplication::translate("sighuppage", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("sighuppage", "sign up", nullptr));
        label->setText(QCoreApplication::translate("sighuppage", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("sighuppage", "password", nullptr));
        label_3->setText(QCoreApplication::translate("sighuppage", "name", nullptr));
        label_4->setText(QCoreApplication::translate("sighuppage", "address", nullptr));
        label_5->setText(QCoreApplication::translate("sighuppage", "telephone", nullptr));
        regi->setText(QCoreApplication::translate("sighuppage", "register", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sighuppage", "back", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class sighuppage: public Ui_sighuppage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGHUPPAGE_H
