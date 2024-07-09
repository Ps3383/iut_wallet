#include "changename.h"
#include "ui_changename.h"
#include"accountpage.h"
#include"mainwindow.h"
#include<QMessageBox>
#include"signinpage.h"

changename::changename(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::changename)
{
    ui->setupUi(this);
}

changename::~changename()
{
    delete ui;
}

void changename::on_pushButton_clicked()
{
    hide();
    accountpage * u;
    u=new accountpage(this);
    u->show();
}


void changename::on_pushButton_2_clicked()
{
    QString nn  = ui->lineEdit->text();
    if(nn!=""){
        MainWindow *main = qobject_cast<MainWindow*>(parent());
        main->changeName(em,nn);
        QMessageBox::information(this, "name", "Successfully added ");

        hide();
        accountpage * y;
        y = new accountpage(this);
        y->show();
    }
    else{
        QMessageBox::warning(this, "name", "enter name!");
    }
}

