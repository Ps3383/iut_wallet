#include "btoe.h"
#include "ui_btoe.h"
#include"trade.h"
#include<QMessageBox>
#include"signinpage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>

BTOE::BTOE(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BTOE)
{
    ui->setupUi(this);
}

BTOE::~BTOE()
{
    delete ui;
}

void BTOE::on_pushButton_clicked()
{
    hide();
    trade * j;
    j =new trade(this);
    j->show();
}

bool Integerr(const QString& str) {
    QRegularExpression re("^-?\\d*(\\.\\d+)?$");
    QRegularExpressionMatch match = re.match(str);
    return match.hasMatch();
}

void BTOE::on_pushButton_2_clicked()
{
    QString adr = ui->adress->text();
    QString sourseamount  = ui->amount->text();
    if((Integerr(sourseamount)) && adr!=""){
        QString email = em; // get from client
        QString source_coin = "BTC"; // get from user(همون جایی که کاربر وارد میکنه یه کاری بکن که مشخص بشه چه کوینی رو انتخاب کرده)
        QString destination_coin = "ETH"; // get from user(همون جایی که کاربر وارد میکنه یه کاری بکن که مشخص بشه چه کوینی رو انتخاب کرده)
        QString destination_address = adr; //get from user
        float source_price,source_amount, destination_price;
        source_price  = 3405.5; //get from api
        destination_price = 750.6; //get from api
        source_amount = sourseamount.toFloat() ; //get from user
        QJsonObject json;
        json["type"] = "transactions";
        json["sellORbuy"] = "trade";
        json["email"] = email;
        json["source_coin"] = source_coin;
        json["destination_coin"] = destination_coin;
        json["source_address"] = "";
        json["destination_address"] = destination_address;
        json["source_amount"] = source_amount;
        json["destination_amount"] = source_amount * source_price / destination_price ;




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
                    QMessageBox::information(this, "Success", "Trade completed successfully!");
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
        QMessageBox::warning(this, "Error", "invalid input!");
    }
}

