#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
     hide();
     re = new sighuppage(this);
     re->show();
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    ss= new signinpage(this);
    ss->show();
}

