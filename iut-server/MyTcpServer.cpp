#include "MyTcpServer.h"
#include "DatabaseManager.h"

MyTcpServer::MyTcpServer(QObject* parent) : QTcpServer(parent) {
    connect(this, &QTcpServer::newConnection, this, &MyTcpServer::onNewConnection);
}

void MyTcpServer::onNewConnection() {
    QTcpSocket* socket = nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::onReadyRead);
}

void MyTcpServer::onReadyRead() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    QByteArray data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
	if (doc.isNull()) {
        qDebug() << "Invalid JSON received";
        socket->write("Invalid JSON");
        socket->flush();
        socket->close();
        return;
    }
    QJsonObject json = doc.object();
	qDebug() << "Received JSON:" << doc.toJson(QJsonDocument::Indented);


    QString type = json["type"].toString();

    if(type=="signup"){
        QString email = json["email"].toString();
        QString password = json["password"].toString();
        QString name = json["name"].toString();
        QString address = json["address"].toString();
        QString phoneNumber = json["phoneNumber"].toString();

        QSqlQuery query;
        query.prepare("INSERT INTO users (email, password, name, address, phoneNumber) VALUES (:email, :password, :name, :address, :phoneNumber)");
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        query.bindValue(":name", name);
        query.bindValue(":address", address);
        query.bindValue(":phoneNumber", phoneNumber);

        if (!query.exec()) {
            qDebug() << "User insert error:" << query.lastError().text();
            socket->write("Error");
        }
        else {
            qDebug() << "User inserted successfully";
            socket->write("Success");
        }
    }
    else if (type == "signin") {
        QString email = json["email"].toString();
        QString password = json["password"].toString();

        QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE email = :email AND password = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        if (!query.exec()) {
            qDebug() << "Select error:" << query.lastError().text();
            socket->write("Error");
        } else {
            if (query.next()) {
                qDebug() << "User exists";
                socket->write("User exists");
            } else {
                qDebug() << "Invalid credentials";
                socket->write("Invalid credentials");
            }
        }
    }
    else if(type == "getWallet"){
        QString email = json["email"].toString();
        QString name = json["walletName"].toString();

        DatabaseManager dbManager("wallets.db");
        QJsonObject json = dbManager.getWallet(email, name);

        QJsonDocument doc(json);
        QByteArray data = doc.toJson();


        socket->write(data);
        socket->flush();
        qDebug() << "data was sent to client";
     }
    else if (type == "addWallet"){

    QString email = json["email"].toString();
    QString name = json["walletName"].toString();

    Wallet myWallet(email, name);

    DatabaseManager dbManager("wallets.db");
    if (dbManager.isOpen()) {
        dbManager.createTable();
        if (dbManager.addWallet(myWallet)) {
            qDebug() << "Wallet added to the database";
        }
    }
    }
    else if(type == "transactions"){
        QString type = json.value("sellORbuy").toString();
        QString email = json.value("email").toString();
        QString sourceCoin = json.value("source_coin").toString();
        QString destinationCoin = json.value("destination_coin").toString();
        QString sourceAddress = json.value("source_address").toString();
        QString destinationAddress = json.value("destination_address").toString();
        float sourceAmount = static_cast<float>(json.value("source_amount").toDouble());
        float destinationAmount = static_cast<float>(json.value("destination_amount").toDouble());

        QSqlQuery query;
        query.prepare("INSERT INTO transactions (sellORbuy, email, source_coin, destination_coin, source_address, destination_address, source_amount, destination_amount ) VALUES (:sellORbuy, :email, :source_coin, :destination_coin, :source_address, :destination_address, :source_amount, :destination_amount)");


        query.bindValue(":sellORbuy", type);
        query.bindValue(":email", email);
        query.bindValue(":source_coin", sourceCoin);
        query.bindValue(":destination_coin", destinationCoin);
        query.bindValue(":source_address", sourceAddress);
        query.bindValue(":destination_address", destinationAddress);
        query.bindValue(":source_amount", sourceAmount);
        query.bindValue(":destination_amount", destinationAmount);


        if (!query.exec()) {
            qDebug() << "Transactions insert error:" << query.lastError().text();
            socket->write("Error");
        }
        else {
            qDebug() << "Transactions inserted successfully";
            socket->write("Success");
        }
     }
    else {
        qDebug() << "Unknown request type";
        socket->write("Unknown request type");
    }

    socket->flush();
    socket->close();
}
    // QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    // if (!socket) return;

    // QByteArray data = socket->readAll();
    // QJsonDocument doc = QJsonDocument::fromJson(data);
    // QJsonObject json = doc.object();

    // QString email = json["email"].toString();
    // QString password = json["password"].toString();
    // QString name = json["name"].toString();
    // QString address = json["address"].toString();
    // QString phoneNumber = json["phoneNumber"].toString();

    // QSqlQuery query;
    // query.prepare("INSERT INTO users (email, password, name, address, phoneNumber) "
    //               "VALUES (?, ?, ?, ?, ?, ?)");
    // query.addBindValue(email);
    // query.addBindValue(password);
    // query.addBindValue(name);
    // query.addBindValue(address);
    // query.addBindValue(phoneNumber);

    // if (!query.exec()) {
    //     qDebug() << "Insert error:" << query.lastError().text();
    //     socket->write("Error");
    // } else {
    //     qDebug() << "Insert success";
    //     socket->write("Success");
    // }

    // socket->flush();
    // socket->close();
// }
// void MyTcpServer::processJsonData(const QJsonObject &json) {
//     QString email = json["email"].toString();
//     QString password = json["password"].toString();
//     QString name = json["name"].toString();
//     QString address = json["address"].toString();
//     QString phoneNumber = json["phoneNumber"].toString();

//     QSqlQuery query;
//     query.prepare("INSERT INTO users (email, password, name, address, phoneNumber) "
//                   "VALUES (?, ?, ?, ?, ?, ?)");
//     query.addBindValue(email);
//     query.addBindValue(password);
//     query.addBindValue(name);
//     query.addBindValue(address);
//     query.addBindValue(phoneNumber);

//     if (!query.exec()) {
//         qDebug() << "Insert error:" << query.lastError().text();
//         socket->write("Error");
//     } else {
//         qDebug() << "Insert success";
//         socket->write("Success");
//     }
// }
