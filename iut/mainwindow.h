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
    void sendUser( User user);
    bool changePassword( QString email,  QString newPassword);
    void changePhoneNumber( QString email,  QString newPhoneNumber);
    void changeAddress( QString email,  QString newAddress);
    void changeName( QString email,  QString newName);
protected slots:
    void onReadyRead() {
        QByteArray data = socket->readAll();
        qDebug() << "Server response:" << data;
    }
    void processServerResponse();
    //void processServerResponsee();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

public:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    sighuppage * re;
    signinpage * ss;
};
//void sendUser( User user);

//extern MainWindow w;

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
