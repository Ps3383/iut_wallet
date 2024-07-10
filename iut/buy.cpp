#include "buy.h"
#include "ui_buy.h"
#include"showwallet.h"
#include<QMessageBox>
#include <QChar>
#include <QCoreApplication>
#include <QString>
#include <QDebug>

buy::buy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::buy)
{
    ui->setupUi(this);
}

buy::~buy()
{
    delete ui;
}

void buy::on_back_clicked()
{
    hide();
    showwallet * j;
    j = new showwallet(this);
    j->show();
}

bool isIntegerr(const QString& str) {
    for (QChar c : str) {
        if (!c.isDigit()) {
            return false;
        }
    }
    return true;
}

void buy::on_buy_2_clicked()
{
    QString btc = ui->linebtc->text();
    QString eth = ui->lineeth->text();
    QString trx = ui->linetrx->text();
    if(btc=="" && eth=="" && trx==""){
        QMessageBox::warning(this, "Error", "say how many you want to buy!");
    }
    else{
            if(btc=="" && eth=="" && trx!=""){
                  if(isIntegerr(trx)){

                  }
                else{
                    QMessageBox::warning(this, "Error", "enter number to buy");
                }
            }
            else if(btc!="" && eth=="" && trx==""){
                if(isIntegerr(btc)){

                }
                else{
                    QMessageBox::warning(this, "Error", "enter number to buy");
                }
            }
            else if(btc=="" && eth!="" && trx==""){
                if(isIntegerr(eth)){

                }
                else{
                    QMessageBox::warning(this, "Error", "enter number to buy");
                }
            }
            else{
                QMessageBox::warning(this, "Error", "you can buy one of them at the moment");
            }
    }

}

