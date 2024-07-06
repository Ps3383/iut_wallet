#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(new QTcpSocket(this)) // مقداردهی اولیه سوکت
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
    ss = new signinpage(this);
    ss->show();
}

void MainWindow::sendUser( User user)
{
    QJsonObject json;
    json["email"] = user.email;
    json["password"] = user.password;
    json["name"] = user.name;
    json["address"] = user.address;
    json["phoneNumber"] = user.phoneNumber;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost("127.0.0.1", 1234);

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "data was sent to server";
    }
    else {
        qDebug() << "Connection failed!";
    }
}
