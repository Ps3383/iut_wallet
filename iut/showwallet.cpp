#include "showwallet.h"
#include "ui_showwallet.h"
#include"mainwindow.h"
#include"accountpage.h"
#include"signinpage.h"
#include"buy.h"
#include"sell.h"

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
    QString wallname = ui->linewalletname->text();
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
    mainWindow->showwallet(em,wallname);
    QString p = mainWindow->getWalletInfo(em,wallname);
    ui->textBrowser->setText(p);
}


void showwallet::on_buy_clicked()
{
    hide();
    buy * y;
    y= new buy(this);
    y->show();
}


void showwallet::on_sell_clicked()
{
    hide();
    sell * y;
    y= new sell(this);
    y->show();
}


void showwallet::on_increase_clicked()
{
    // increase usus
}


void showwallet::on_decrease_clicked()
{
    // decrease usus
}

