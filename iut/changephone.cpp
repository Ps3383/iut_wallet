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
    if(phph!=""){
        MainWindow *main = qobject_cast<MainWindow*>(parent());
        main->changePhoneNumber(em,phph);
        QMessageBox::information(this, "phone number", "Successfully added");
        hide();
        accountpage * y;
        y = new accountpage(this);
        y->show();
    }
    else{
        QMessageBox::warning(this, "change phone number", "enter phone number!");
    }
}

