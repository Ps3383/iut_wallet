#include "showwallet.h"
#include "ui_showwallet.h"
#include"mainwindow.h"
#include"accountpage.h"
#include"signinpage.h"

showwallet::showwallet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::showwallet)
{
    ui->setupUi(this);
}

showwallet::~showwallet()
{
    delete ui;
}

void showwallet::on_pushButton_clicked()
{
    hide();
    accountpage * y;
    y= new accountpage(this);
    y->show();
}



void showwallet::on_shw_clicked()
{
    QString wallet = ui->linewalletname->text();

}

