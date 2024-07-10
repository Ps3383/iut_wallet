#include "changephone.h"
#include "ui_changephone.h"
#include"accountpage.h"
#include"signinpage.h"
#include"mainwindow.h"
#include<QMessageBox>


changephone::changephone(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changephone)
{
    ui->setupUi(this);
}

changephone::~changephone()
{
    delete ui;
}

void changephone::on_backk_clicked()
{
    hide();
    accountpage * y;
    y = new accountpage(this);
    y->show();
}


void changephone::on_addd_clicked()
{
    QString phph = ui->lineEdit->text();
    QRegularExpression regexx(R"((^\+?[0-9]{1,4}?[-.\s]?(\(?\d{1,3}?\)?[-.\s]?)?\d{1,4}[-.\s]?\d{1,4}[-.\s]?\d{1,9}$))");
    QRegularExpressionMatch matchh = regexx.match(phph);
    if((matchh.hasMatch()) && phph.size()>=10){
        MainWindow *main = qobject_cast<MainWindow*>(parent());
        main->changePhoneNumber(em,phph);
        QMessageBox::information(this, "phone number", "Successfully added");
        hide();
        accountpage * y;
        y = new accountpage(this);
        y->show();
    }
    else{
        QMessageBox::warning(this, "change phone number", "Invalid phonenumber format");
    }
}

