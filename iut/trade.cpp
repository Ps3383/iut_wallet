#include "trade.h"
#include "ui_trade.h"
#include"showwallet.h"
#include"btoe.h"
#include"btot.h"
#include"etob.h"
#include"etot.h"
#include"ttob.h"
#include"ttoe.h"

trade::trade(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trade)
{
    ui->setupUi(this);
}

trade::~trade()
{
    delete ui;
}

void trade::on_back_clicked()
{
    hide();
    showwallet * j;
    j =new showwallet(this);
    j->show();
}





void trade::on_BtoE_clicked()
{
    hide();
    BTOE * j;
    j =new BTOE(this);
    j->show();
}


void trade::on_BtoT_clicked()
{
    hide();
    BTOT * j;
    j =new BTOT(this);
    j->show();
}


void trade::on_EtoB_clicked()
{
    hide();
    ETOB * j;
    j =new ETOB(this);
    j->show();
}


void trade::on_EtoT_clicked()
{
    hide();
    ETOT * j;
    j =new ETOT(this);
    j->show();
}


void trade::on_TtoB_clicked()
{
    hide();
    TTOB * j;
    j =new TTOB(this);
    j->show();
}


void trade::on_TtoE_clicked()
{
    hide();
    TTOE * j;
    j =new TTOE(this);
    j->show();
}

