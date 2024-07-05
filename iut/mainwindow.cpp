#include "mainwindow.h"
#include "ui_mainwindow.h"


//MainWindow w = nullptr;
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

void sendUser( User user){
    MainWindow s;
    QJsonObject json;
    json["email"] = user.email;
    json["password"] = user.password;
    json["name"] = user.name;
    json["address"] = user.address;
    json["phoneNumber"] = user.phoneNumber;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    s.socket->connectToHost("127.0.0.1", 1234);
    if (s.socket->waitForConnected(3000)) {
        s.socket->write(data);
        s.socket->flush();
        qDebug()<<"data was sent to server";

    }
    else {
        qDebug() << "Connection failed!";
    }

}


