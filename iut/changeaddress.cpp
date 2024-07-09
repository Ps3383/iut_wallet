#include "changeaddress.h"
#include "ui_changeaddress.h"
#include"accountpage.h"
#include"mainwindow.h"
#include<QMessageBox>
#include"signinpage.h"


changeaddress::changeaddress(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changeaddress)
{
    ui->setupUi(this);
}

changeaddress::~changeaddress()
{
    delete ui;
}

void changeaddress::on_backkk_clicked()
{
    hide();
    accountpage * u;
    u=new accountpage(this);
    u->show();
}


void changeaddress::on_adddd_clicked()
{
    QString addddd  = ui->lineEdit->text();
    if(addddd!=""){
        MainWindow *main = qobject_cast<MainWindow*>(parent());
        main->changePassword(em, addddd);
        QMessageBox::information(this, "address", "Successfully added ");

        hide();
        accountpage * y;
        y = new accountpage(this);
        y->show();
    }
    else{
        QMessageBox::warning(this, "address", "enter address!");
    }
}

