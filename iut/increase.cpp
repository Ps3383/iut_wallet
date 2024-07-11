#include "increase.h"
#include "ui_increase.h"
#include"showwallet.h"
#include<QMessageBox>
#include"signinpage.h"
#include<QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

increase::increase(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::increase)
{
    ui->setupUi(this);
}

increase::~increase()
{
    delete ui;
}

void increase::on_pushButton_clicked()
{
    hide();
    showwallet * h;
    h=new showwallet(this);
    h->show();
}

bool isIntegerrr(const QString& str) {
    QRegularExpression re("^-?\\d*(\\.\\d+)?$");
    QRegularExpressionMatch match = re.match(str);
    return match.hasMatch();
}

void increase::on_increase_2_clicked()
{
    QString c = ui->linecoin->text();
    if(isIntegerrr(c)){
        QString email = em; // get from client
        float coin_amount;
        coin_amount = c.toFloat();
        QJsonObject json;
        json["type"] = "transactions";
        json["sellORbuy"] = "increase";
        json["email"] = em;
        json["source_coin"] = "";
        json["destination_coin"] = "usdt";
        json["source_address"] = "";
        json["destination_address"] = "";
        json["source_amount"] = 0.0 ;
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
        QMessageBox::warning(this, "Error", "enter number!");
    }
}

