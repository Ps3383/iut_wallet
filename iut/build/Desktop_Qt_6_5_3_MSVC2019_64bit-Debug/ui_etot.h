/********************************************************************************
** Form generated from reading UI file 'etot.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETOT_H
#define UI_ETOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ETOT
{
public:
    QGroupBox *groupBox;
    QPushButton *back;
    QPushButton *ok;
    QLineEdit *adress;
    QLineEdit *amount;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *ETOT)
    {
        if (ETOT->objectName().isEmpty())
            ETOT->setObjectName("ETOT");
        ETOT->resize(791, 474);
        groupBox = new QGroupBox(ETOT);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(110, 70, 581, 351));
        back = new QPushButton(groupBox);
        back->setObjectName("back");
        back->setGeometry(QRect(360, 300, 80, 24));
        ok = new QPushButton(groupBox);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(460, 300, 80, 24));
        adress = new QLineEdit(groupBox);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(200, 60, 113, 24));
        amount = new QLineEdit(groupBox);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(200, 120, 113, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 121, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 110, 111, 41));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 190, 151, 111));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/ETH.jfif);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 190, 151, 111));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/TRX.jfif);"));

        retranslateUi(ETOT);

        QMetaObject::connectSlotsByName(ETOT);
    } // setupUi

    void retranslateUi(QDialog *ETOT)
    {
        ETOT->setWindowTitle(QCoreApplication::translate("ETOT", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ETOT", "ETH to TRX", nullptr));
        back->setText(QCoreApplication::translate("ETOT", "back", nullptr));
        ok->setText(QCoreApplication::translate("ETOT", "OK", nullptr));
        label->setText(QCoreApplication::translate("ETOT", "destination address", nullptr));
        label_2->setText(QCoreApplication::translate("ETOT", "source amount", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ETOT: public Ui_ETOT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETOT_H
