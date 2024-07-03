#include "sighuppage.h"
#include "ui_sighuppage.h"
#include"mainwindow.h"

sighuppage::sighuppage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sighuppage)
{
    ui->setupUi(this);
}

sighuppage::~sighuppage()
{
    delete ui;
}

void sighuppage::on_pushButton_2_clicked()
{
    hide();
    MainWindow * b;
    b = new MainWindow(this);
    b->show();
}

