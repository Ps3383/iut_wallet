#include "sell.h"
#include "ui_sell.h"
#include"showwallet.h"
#include<QMessageBox>
#include <QChar>
#include <QCoreApplication>
#include <QString>
#include <QDebug>

sell::sell(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sell)
{
    ui->setupUi(this);
}

sell::~sell()
{
    delete ui;
}

void sell::on_back_clicked()
{
    hide();
    showwallet * i;
    i=new showwallet(this);
    i->show();
}

bool isInteger(const QString& str) {
    for (QChar c : str) {
        if (!c.isDigit()) {
            return false;
        }
    }
    return true;
}

void sell::on_sell_2_clicked()
{
    QString btc = ui->linebtc->text();
    QString eth = ui->lineeth->text();
    QString trx = ui->linetrx->text();
    if(btc=="" && eth=="" && trx==""){
        QMessageBox::warning(this, "Error", "say how many you want to sell!");
    }
    else{
        if(btc=="" && eth=="" && trx!=""){
            if(isInteger(trx)){

            }
            else{
                QMessageBox::warning(this, "Error", "enter number to sell");
            }
        }
        else if(btc!="" && eth=="" && trx==""){
            if(isInteger(btc)){

            }
            else{
                QMessageBox::warning(this, "Error", "enter number to sell");
            }
        }
        else if(btc=="" && eth!="" && trx==""){
            if(isInteger(eth)){

            }
            else{
                QMessageBox::warning(this, "Error", "enter number to sell");
            }
        }
        else{
            QMessageBox::warning(this, "Error", "you can sell one of them at the moment");
        }
    }
}

