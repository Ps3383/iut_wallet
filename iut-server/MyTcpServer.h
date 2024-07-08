#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class MyTcpServer : public QTcpServer {
    Q_OBJECT
public:
    MyTcpServer(QObject* parent = nullptr);

public slots:
    void onNewConnection();
    void onReadyRead();

private:
    void processJsonData(const QJsonObject &json);

};

#endif // MYTCPSERVER_H
