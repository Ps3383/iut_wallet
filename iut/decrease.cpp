#include "decrease.h"
#include "ui_decrease.h"
#include"showwallet.h"
#include<QMessageBox>
#include"signinpage.h"
#include <QJsonDocument>
#include <QJsonObject>

decrease::decrease(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::decrease)
{
    ui->setupUi(this);
}

decrease::~decrease()
{
    delete ui;
}

void decrease::on_pushButton_clicked()
{
    hide();
    showwallet * k;
    k =new showwallet(this);
    k->show();
}

bool iisIntegerr(const QString& str) {
    QRegularExpression re("^-?\\d*(\\.\\d+)?$");
    QRegularExpressionMatch match = re.match(str);
    return match.hasMatch();
}

void decrease::on_decreease_clicked()
{
    QString c = ui->linecoin->text();
    if(iisIntegerr(c)){
        QString email = em; // get from client
        float coin_amount;
        coin_amount = c.toFloat();
        QJsonObject json;
        json["type"] = "transactions";
        json["sellORbuy"] = "decrease";
        json["email"] = email;
        json["source_coin"] = "usdt";
        json["destination_coin"] = "";
        json["source_address"] = "";
        json["destination_address"] = "";
        json["source_amount"] = coin_amount ;
        json["destination_amount"] = 0.0;

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

