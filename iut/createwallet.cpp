#include "createwallet.h"
#include "ui_createwallet.h"
#include"accountpage.h"
#include"mainwindow.h"
#include"signinpage.h"
#include<QMessageBox>

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
    QString walname = ui->lineEdit->text();
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());

    mainWindow->addWallet(em,walname);
    QMessageBox::information(this, "create wallet", "Successfully created!");
    hide();
    accountpage *e = new accountpage(this);
    e->show();
}

