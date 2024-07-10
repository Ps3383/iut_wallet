#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include"signinpage.h"
#include <QMessageBox>
#include"accountpage.h"
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
    // فراخوانی تابع initialize بعد از نمایش صفحه
    ss->show();

}

void MainWindow::sendUser( User user)
{

    //socket=(new QTcpSocket(this));
    QJsonObject json;
    json["type"] = "signup";
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

        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::processServerResponse);

    }
    else {
        qDebug() << "Connection failed!";
    }
    //socket->close();
    //socket->deleteLater();
}

void MainWindow::processServerResponse() {
    QByteArray response = socket->readAll();
    QString responseStr(response);
    if (responseStr == "Email already exists" || responseStr == "Password already exists") {
        QMessageBox::warning(this, "Sign Up Error", responseStr);
    } else if (responseStr == "Success") {
        QMessageBox::information(this, "Sign Up", "Successfully signed up");
    } else {
        QMessageBox::warning(this, "Sign Up Error", "An error occurred during sign up");
    }

    socket->close();
}


bool MainWindow::changePassword( QString email,  QString newPassword)
{
QTcpSocket* sockett = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "change_password";  // اضافه کردن نوع درخواست به JSON
    json["email"] = email;
    json["new_password"] = newPassword;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

     sockett->connectToHost("127.0.0.1", 1234);

    if (sockett->waitForConnected(3000)) {
        sockett->write(data);
        sockett->flush();
        qDebug() << "Password change request sent to server";
        connect(sockett, &QTcpSocket::readyRead, [this,sockett]() {
            QByteArray response = sockett->readAll();
            QString responseStr(response);
            if (responseStr == "Success") {
                //QMessageBox::information(this, "Change Password", "Password changed successfully");
                return true;
                // hide();
                // accountpage * y;
                // y = new accountpage(this);
                // y->show();
            }
            else {
                //QMessageBox::warning(this, "Change Password Error", "An error occurred while changing password");
                return false;

                // hide();
                // accountpage * y;
                // y = new accountpage(this);
                // y->show();
            }
             //sockett->close();
        });

    } else {
        qDebug() << "Connection failed!";
        return false;
    }
    sockett->close();
    sockett->deleteLater();
}



void MainWindow::changePhoneNumber( QString email,  QString newPhoneNumber)
{
    QTcpSocket* socket = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "change_phone_number";  // اضافه کردن نوع درخواست به JSON
    json["email"] = email;
    json["new_phone_number"] = newPhoneNumber;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost("127.0.0.1", 1234);  // استفاده از QHostAddress::LocalHost

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "Phone number change request sent to server";
    } else {
        qDebug() << "Connection failed! Error:" << socket->errorString();
    }
    socket->close();
    socket->deleteLater();
}

void MainWindow::changeAddress( QString email,  QString newAddress)
{
    QTcpSocket* socket = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "change_address";  // اضافه کردن نوع درخواست به JSON
    json["email"] = email;
    json["new_address"] = newAddress;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost(QHostAddress::LocalHost, 1234);  // استفاده از QHostAddress::LocalHost

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "Address change request sent to server";
    } else {
        qDebug() << "Connection failed! Error:" << socket->errorString();
    }

    socket->close();
    socket->deleteLater();
}

void MainWindow::changeName( QString email,  QString newName)
{
    QTcpSocket* socket = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "change_name";  // اضافه کردن نوع درخواست به JSON
    json["email"] = email;
    json["new_name"] = newName;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost(QHostAddress::LocalHost, 1234);  // استفاده از QHostAddress::LocalHost

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "Name change request sent to server";
    } else {
        qDebug() << "Connection failed! Error:" << socket->errorString();
    }

    socket->close();
    socket->deleteLater();
}

void MainWindow::addWallet( QString email,  QString walletName)
{
    QTcpSocket* socket = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "addWallet";
    json["email"] = email;
    json["wallet_name"] = walletName;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost("127.0.0.1", 1234);

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "Add wallet request sent to server";
    }
}

void MainWindow::showwallet( QString email,  QString walletName)
{
    QTcpSocket* socket = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "getWallet";
    json["email"] = email;
    json["wallet_name"] = walletName;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost("127.0.0.1", 1234);

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "try to show wallet";
    }
}


QString MainWindow::getWalletInfo(QString email, QString walletName)
{
    QString ss;
    QTcpSocket* socket = new QTcpSocket(this);

    QJsonObject json;
    json["type"] = "getWallet";
    json["email"] = email;
    json["walletName"] = walletName;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    socket->connectToHost("127.0.0.1", 1234);

    if (socket->waitForConnected(3000)) {
        socket->write(data);
        socket->flush();
        qDebug() << "Wallet info request sent to server";

        QEventLoop loop;
        connect(socket, &QTcpSocket::readyRead, [this, socket, &ss, &loop]() {
            QByteArray response = socket->readAll();
            qDebug() << "Received response from server:" << response;

            QJsonDocument doc = QJsonDocument::fromJson(response);
            QJsonObject json = doc.object();
            QString info;

            if (json["status"] == "success") {
                info += "Email: " + json["email"].toString() + "\n";
                info += "BTC Balance: " + QString::number(json["btc_balance"].toInt()) + "\n";
                info += "BTC Price: " + QString::number(json["btc_price"].toInt()) + "\n";
                info += "BTC Address: " + json["btc_address"].toString() + "\n";
                info += "ETH Balance: " + QString::number(json["eth_balance"].toInt()) + "\n";
                info += "ETH Price: " + QString::number(json["eth_price"].toInt()) + "\n";
                info += "ETH Address: " + json["eth_address"].toString() + "\n";
                info += "TRX Balance: " + QString::number(json["trx_balance"].toInt()) + "\n";
                info += "TRX Price: " + QString::number(json["trx_price"].toInt()) + "\n";
                info += "TRX Address: " + json["trx_address"].toString() + "\n";
                info += "USDT: " + QString::number(json["usdt"].toDouble()) + "\n";

                QJsonArray wordsArray = json["words"].toArray();
                info += "Words: ";
                for (int i = 0; i < wordsArray.size(); ++i) {
                    info += wordsArray[i].toString() + " ";
                }
                info += "\n";
                ss = info;
            }

            socket->close();
            socket->deleteLater();
            loop.quit();
        });

        loop.exec(); // Wait here until readyRead() is called
    } else {
        qDebug() << "Connection failed!";
        socket->deleteLater();
        return "null";
    }

    return ss;

}






