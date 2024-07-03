#include "signinpage.h"
#include "ui_signinpage.h"
#include"mainwindow.h"

signinpage::signinpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinpage)
{
    ui->setupUi(this);
}

signinpage::~signinpage()
{
    delete ui;
}

void signinpage::on_pushButton_2_clicked()
{
    hide();
    MainWindow * b;
    b = new MainWindow(this);
    b->show();
}

