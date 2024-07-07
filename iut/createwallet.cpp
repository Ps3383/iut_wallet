#include "createwallet.h"
#include "ui_createwallet.h"
#include"accountpage.h"

createwallet::createwallet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createwallet)
{
    ui->setupUi(this);
}

createwallet::~createwallet()
{
    delete ui;
}

void createwallet::on_pushButton_2_clicked()
{
    hide();
    accountpage *e = new accountpage(this);
    e->show();
}


void createwallet::on_create_clicked()
{
    //create wallet from server
}

