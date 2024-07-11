#include "buy.h"
#include "ui_buy.h"
#include"showwallet.h"
#include<QMessageBox>
#include <QChar>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include"signinpage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>

buy::buy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::buy)
{
    ui->setupUi(this);
}

buy::~buy()
{
    delete ui;
}

void buy::on_back_clicked()
{
    hide();
    showwallet * j;
    j = new showwallet(this);
    j->show();
}

bool isIntegerr(const QString& str) {
    QRegularExpression re("^-?\\d*(\\.\\d+)?$");
    QRegularExpressionMatch match = re.match(str);
    return match.hasMatch();
}

void buy::on_buy_2_clicked()
{
    QString btc = ui->linebtc->text();
    QString eth = ui->lineeth->text();
    QString trx = ui->linetrx->text();
    if(btc=="" && eth=="" && trx==""){
        QMessageBox::warning(this, "Error", "say how many you want to buy!");
    }
    else{
            if(btc=="" && eth=="" && trx!=""){
                  if(isIntegerr(trx)){
                    QString email = em; // get from client
                    QString buy_coin = "TRX";
                    float coin_price,coin_amount;
                    coin_price  = 3405.5;   //get from api
                    coin_amount = trx.toFloat();   //get from user
                    QJsonObject json;
                    json["type"] = "transactions";
                    json["sellORbuy"] = "buy";
                    json["email"] = email;
                    json["source_coin"] = "usdt";
                    json["destination_coin"] = buy_coin;
                    json["source_address"] = "";
                    json["destination_address"] = "";
                    json["source_amount"] = coin_amount * coin_price;
                    json["destination_amount"] = coin_amount;

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
                    QMessageBox::warning(this, "Error", "enter number to buy");
                }
            }
            else if(btc!="" && eth=="" && trx==""){
                if(isIntegerr(btc)){
                    QString email = em; // get from client
                    QString buy_coin = "BTC";
                    float coin_price,coin_amount;
                    coin_price  = 3405.5;   //get from api
                    coin_amount = btc.toFloat();   //get from user
                    QJsonObject json;
                    json["type"] = "transactions";
                    json["sellORbuy"] = "buy";
                    json["email"] = email;
                    json["source_coin"] = "usdt";
                    json["destination_coin"] = buy_coin;
                    json["source_address"] = "";
                    json["destination_address"] = "";
                    json["source_amount"] = coin_amount * coin_price;
                    json["destination_amount"] = coin_amount;

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
                    QMessageBox::warning(this, "Error", "enter number to buy");
                }
            }
            else if(btc=="" && eth!="" && trx==""){
                if(isIntegerr(eth)){
                    QString email = em; // get from client
                    QString buy_coin = "ETH";
                    float coin_price,coin_amount;
                    coin_price  = 3405.5;   //get from api
                    coin_amount = eth.toFloat();   //get from user
                    QJsonObject json;
                    json["type"] = "transactions";
                    json["sellORbuy"] = "buy";
                    json["email"] = email;
                    json["source_coin"] = "usdt";
                    json["destination_coin"] = buy_coin;
                    json["source_address"] = "";
                    json["destination_address"] = "";
                    json["source_amount"] = coin_amount * coin_price;
                    json["destination_amount"] = coin_amount;

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
                    QMessageBox::warning(this, "Error", "enter number to buy");
                }
            }
            else{
                QMessageBox::warning(this, "Error", "you can buy one of them at the moment");
            }
    }

}

