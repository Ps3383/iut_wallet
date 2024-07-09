#include "changepass.h"
#include "ui_changepass.h"
#include"accountpage.h"
#include"signinpage.h"
#include"mainwindow.h"
#include<QMessageBox>

changeinfo::changeinfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changeinfo)
{
    ui->setupUi(this);
}

changeinfo::~changeinfo()
{
    delete ui;
}




void changeinfo::on_pushButton_clicked()
{
    hide();
    accountpage * oo;
    oo =new accountpage(this);
    oo->show();
}


void changeinfo::on_changep_clicked()
{
    QString newpass = ui->linepassn->text();

    if((ui->linepp->text())==ps){
        if(ui->linepass->text()==ui->linepassn->text()){
            if(ui->linepassn->text()!=""){
                MainWindow *main = qobject_cast<MainWindow*>(parent());
                   bool x =  main->changePassword(em, newpass);
                   if(x==true){
                    QMessageBox::information(this, "change password", "Successfully change ");
                   }
                   else{
                       QMessageBox::warning(this, "Change Password Error", "An error occurred while changing password");
                   }
                    hide();
                    accountpage * y;
                    y = new accountpage(this);
                    y->show();
            }
            else{
                QMessageBox::warning(this, "change passowrd", "enter password!");
            }
        }
        else{
            QMessageBox::warning(this, "change passowrd", "must be same password");
        }
    }
    else{
        QMessageBox::warning(this, "change passowrd", "Invalid password!");
    }
}

