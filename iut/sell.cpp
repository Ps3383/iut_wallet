#include "sell.h"
#include "ui_sell.h"
#include"showwallet.h"
#include<QMessageBox>
#include"signinpage.h"
#include <QChar>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>
#include<QTcpSocket>

sell::sell(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sell)
{
    ui->setupUi(this);
}

sell::~sell()
{
    delete ui;
}

void sell::on_back_clicked()
{
    hide();
    showwallet * i;
    i=new showwallet(this);
    i->show();
}

bool isInteger(const QString& str) {
    QRegularExpression re("^-?\\d*(\\.\\d+)?$");
    QRegularExpressionMatch match = re.match(str);
    return match.hasMatch();
}

void sell::on_sell_2_clicked()
{
    QString btc = ui->linebtc->text();
    QString eth = ui->lineeth->text();
    QString trx = ui->linetrx->text();
    if(btc=="" && eth=="" && trx==""){
        QMessageBox::warning(this, "Error", "say how many you want to sell!");
    }
    else{
        if(btc=="" && eth=="" && trx!=""){
            if(isInteger(trx)){
                QString email = em; // get from client
                QString sell_coin = "trx"; // get from user
                float coin_price,coin_amount;
                coin_price  = 0.1347; //get from api
                coin_amount = trx.toFloat(); //get from user
                QJsonObject json;
                json["type"] = "transactions";
                json["sellORbuy"] = "sell";
                json["email"] = email;
                json["source_coin"] = sell_coin;
                json["destination_coin"] = "usdt";
                json["source_address"] = "";
                json["destination_address"] = "";
                json["source_amount"] = coin_amount ;
                json["destination_amount"] = coin_amount * coin_price;

                QJsonDocument doc(json);
                QByteArray data = doc.toJson();

                QTcpSocket *socket = new QTcpSocket(this);

                socket->connectToHost("127.0.0.1", 1234);

                if (socket->waitForConnected(3000)) {
                    qDebug() << "Connected to server";

                    socket->write(data);
                    socket->flush();
                    qDebug() << "Data sent to server";

                    // مدیریت پاسخ سرور
                    connect(socket, &QTcpSocket::readyRead, [this, socket]() {
                        QByteArray response = socket->readAll();
                        qDebug() << "Received response from server:" << response;

                        // QJsonDocument responseDoc = QJsonDocument::fromJson(response);
                        // QJsonObject responseObject = responseDoc.object();
                        // QString status = responseObject["status"].toString();
                        QString status(response);

                        if (status == "SuccessSuccess") {
                            QMessageBox::information(this, "Success", "Transaction successful!");
                        } else {
                            QMessageBox::warning(this, "Error", "Transaction failed!");
                        }

                        socket->close();
                        socket->deleteLater();
                    });


                }
                else {
                    qDebug() << "Connection failed!";
                    QMessageBox::warning(this, "Error", "Could not connect to server.");
                    socket->deleteLater();
                }




            }
            else{
                QMessageBox::warning(this, "Error", "enter number to sell");
            }
        }
        else if(btc!="" && eth=="" && trx==""){
            if(isInteger(btc)){
                QString email = em; // get from client
                QString sell_coin = "btc"; // get from use
                float coin_price,coin_amount;
                coin_price  = 57669; //get from api
                coin_amount = btc.toFloat(); //get from user
                QJsonObject json;
                json["type"] = "transactions";
                json["sellORbuy"] = "sell";
                json["email"] = email;
                json["source_coin"] = sell_coin;
                json["destination_coin"] = "usdt";
                json["source_address"] = "";
                json["destination_address"] = "";
                json["source_amount"] = coin_amount ;
                json["destination_amount"] = coin_amount * coin_price;

                QJsonDocument doc(json);
                QByteArray data = doc.toJson();

                QTcpSocket *socket = new QTcpSocket(this);

                socket->connectToHost("127.0.0.1", 1234);

                if (socket->waitForConnected(3000)) {
                    qDebug() << "Connected to server";

                    socket->write(data);
                    socket->flush();
                    qDebug() << "Data sent to server";

                    // مدیریت پاسخ سرور
                    connect(socket, &QTcpSocket::readyRead, [this, socket]() {
                        QByteArray response = socket->readAll();
                        qDebug() << "Received response from server:" << response;

                        // QJsonDocument responseDoc = QJsonDocument::fromJson(response);
                        // QJsonObject responseObject = responseDoc.object();
                        // QString status = responseObject["status"].toString();
                        QString status(response);

                        if (status == "SuccessSuccess") {
                            QMessageBox::information(this, "Success", "Transaction successful!");
                        } else {
                            QMessageBox::warning(this, "Error", "Transaction failed!");
                        }

                        socket->close();
                        socket->deleteLater();
                    });


                }
                else {
                    qDebug() << "Connection failed!";
                    QMessageBox::warning(this, "Error", "Could not connect to server.");
                    socket->deleteLater();
                }



            }
            else{
                QMessageBox::warning(this, "Error", "enter number to sell");
            }
        }
        else if(btc=="" && eth!="" && trx==""){
            if(isInteger(eth)){
                QString email = em; // get from client
                QString sell_coin = "eth";
                float coin_price,coin_amount;
                coin_price  = 3125.12; //get from api
                coin_amount = eth.toFloat(); //get from user
                QJsonObject json;
                json["type"] = "transactions";
                json["sellORbuy"] = "sell";
                json["email"] = email;
                json["source_coin"] = sell_coin;
                json["destination_coin"] = "usdt";
                json["source_address"] = "";
                json["destination_address"] = "";
                json["source_amount"] = coin_amount ;
                json["destination_amount"] = coin_amount * coin_price;

                QJsonDocument doc(json);
                QByteArray data = doc.toJson();

                QTcpSocket *socket = new QTcpSocket(this);

                socket->connectToHost("127.0.0.1", 1234);

                if (socket->waitForConnected(3000)) {
                    qDebug() << "Connected to server";

                    socket->write(data);
                    socket->flush();
                    qDebug() << "Data sent to server";

                    // مدیریت پاسخ سرور
                    connect(socket, &QTcpSocket::readyRead, [this, socket]() {
                        QByteArray response = socket->readAll();
                        qDebug() << "Received response from server:" << response;

                        // QJsonDocument responseDoc = QJsonDocument::fromJson(response);
                        // QJsonObject responseObject = responseDoc.object();
                        // QString status = responseObject["status"].toString();
                        QString status(response);

                        if (status == "SuccessSuccess") {
                            QMessageBox::information(this, "Success", "Transaction successful!");
                        } else {
                            QMessageBox::warning(this, "Error", "Transaction failed!");
                        }

                        socket->close();
                        socket->deleteLater();
                    });


                }
                else {
                    qDebug() << "Connection failed!";
                    QMessageBox::warning(this, "Error", "Could not connect to server.");
                    socket->deleteLater();
                }


            }
            else{
                QMessageBox::warning(this, "Error", "enter number to sell");
            }
        }
        else{
            QMessageBox::warning(this, "Error", "you can sell one of them at the moment");
        }
    }
}

