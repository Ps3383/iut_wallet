#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"sighuppage.h"
#include"signinpage.h"
#include"user.h"
#include <QMainWindow>
#include<QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sendUser(const User& user) {
        QJsonObject json;
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
        } else {
            qDebug() << "Connection failed!";
        }
    }

protected slots:
    void onReadyRead() {
        QByteArray data = socket->readAll();
        qDebug() << "Server response:" << data;
    }
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    sighuppage * re;
    signinpage * ss;
};


// class User {
// public:
//     QString email;
//     QString password;
//     QString name;
//     QString address;
//     QString phoneNumber;

//     // Constructor
//     User(const QString& email, const QString& password, const QString& name,
//          const QString& address, const QString& phoneNumber)
//         : email(email), password(password), firstName(firstName), lastName(lastName),
//         address(address), phoneNumber(phoneNumber) {}
// };
#endif // MAINWINDOW_H
