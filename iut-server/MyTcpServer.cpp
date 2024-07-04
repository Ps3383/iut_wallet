#include "MyTcpServer.h"

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
        qDebug() << "Insert error:" << query.lastError().text();
        socket->write("Error");
    } else {
		qDebug() << "Data inserted successfully";
        socket->write("Success");
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
