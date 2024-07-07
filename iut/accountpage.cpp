#include "accountpage.h"
#include "ui_accountpage.h"
#include"mainwindow.h"
#include"createwallet.h"

accountpage::accountpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::accountpage)
{
    ui->setupUi(this);
}

accountpage::~accountpage()
{
    delete ui;
}

void accountpage::on_pushButton_2_clicked()
{
    hide();
    MainWindow * b;
    b = new MainWindow(this);
    b->show();
}



void accountpage::on_createwallet_clicked()
{
    hide();
    createwallet * b;
    b = new createwallet(this);
    b->show();
}

