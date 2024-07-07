#include "signinpage.h"
#include "ui_signinpage.h"
#include"mainwindow.h"
#include"accountpage.h"
#include<QMessageBox>

signinpage::signinpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinpage)
{
    ui->setupUi(this);
}

void signinpage::setupconnection(){

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


void signinpage::on_login_clicked()
{
    ssocket = new QTcpSocket(this);

    connect(ssocket, &QTcpSocket::readyRead, this, &signinpage::onReadyRead);
    connect(ssocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred),
            this, &signinpage::onError);
    QString em = ui->lineemail->text();
    QString ps = ui->linepassword->text();

    QJsonObject json;
    json["type"] = "signin";
    json["email"] = em;
    json["password"] = ps;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();


    qDebug() << "data was sent to server";

    ssocket->connectToHost("127.0.0.1", 1234);
    qDebug() << "data was sent to server";


    if (ssocket->waitForConnected(3000)) {
        ssocket->write(data);
        ssocket->flush();
        qDebug() << "data was sent to server";
    }
    else {
        qDebug() << "Connection failed!";
    }
    // else{
    //     QMessageBox::warning(this,"sign up","fill up email and password!");
    // }
}


void signinpage::onReadyRead()
{
    //connect(ssocket, &QTcpSocket::readyRead, this, &signinpage::onReadyRead);
    QByteArray data = ssocket->readAll();
    QString response(data);

    if (response == "User exists") {
        hide();
        accountpage * b;
        b = new accountpage(this);
        b->show();
    } else if (response == "Invalid credentials") {
        QMessageBox::warning(this, "Signin", "Invalid email or password!");
    } else {
        QMessageBox::warning(this, "Signin", "Error occurred while signing in!");
    }

    ssocket->close();
}

void signinpage::onError(QAbstractSocket::SocketError socketError)
{
    // connect(ssocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred),
    //         this, &signinpage::onError);
    qDebug() << "Socket error:" << ssocket->errorString();
}
