#include "signinpage.h"
#include "ui_signinpage.h"
#include"mainwindow.h"
#include"accountpage.h"
#include<QMessageBox>

signinpage::signinpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinpage)
{
    ui->setupUi(this);
}

signinpage::~signinpage()
{
    delete ui;
}

void signinpage::on_pushButton_2_clicked()
{
    hide();
    MainWindow * b;
    b = new MainWindow(this);
    b->show();
}


void signinpage::on_login_clicked()
{
    QString em = ui->lineemail->text();
    QString ps = ui->linepassword->text();
    if(em=="p" && ps=="p"){
        hide();
        accountpage * b;
        b = new accountpage(this);
        b->show();
    }
    else{
        QMessageBox::warning(this,"sign up","fill up email and password!");
    }
}

