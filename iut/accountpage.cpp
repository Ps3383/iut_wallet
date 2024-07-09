#include "accountpage.h"
#include "ui_accountpage.h"
#include"mainwindow.h"
#include"createwallet.h"
#include"changepass.h"
#include"changephone.h"
#include"changeaddress.h"
#include"changename.h"

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


void accountpage::on_change_clicked()
{
    hide();
    changeinfo * j;
    j = new changeinfo(this);
    j->show();
}




void accountpage::on_changeph_clicked()
{
    hide();
    changephone * p;
    p = new changephone(this);
    p->show();

}


void accountpage::on_changea_clicked()
{
    hide();
    changeaddress * t;
    t = new changeaddress(this);
    t->show();
}


void accountpage::on_changen_clicked()
{
    hide();
    changename * t;
    t = new changename(this);
    t->show();
}

