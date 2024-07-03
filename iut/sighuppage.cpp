#include "sighuppage.h"
#include "ui_sighuppage.h"
#include"mainwindow.h"
#include<QMessageBox>

//MainWindow s;
sighuppage::sighuppage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sighuppage)
{
    ui->setupUi(this);
}

sighuppage::~sighuppage()
{
    delete ui;
}

void sighuppage::on_pushButton_2_clicked()
{
    hide();
    MainWindow * b;
    b = new MainWindow(this);
    b->show();
}




void sighuppage::on_regi_clicked()
{
    QString em  = ui->lineemail->text();
    QString ps = ui->linepassword->text();
    QString adr = ui->lineaddress->text();
    QString tel = ui->linetele->text();
    QString na = ui->linename->text();
    if(em!="" && ps!=""){
        User user1(em,ps,na,adr,tel);
        QMessageBox::information(this,"sign up","successfully added");
       // s.sendUser(user1);
    }
    else{
        QMessageBox::warning(this,"sign up","fill up email and password!");
    }
}

