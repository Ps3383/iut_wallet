#include "mainwindow.h"
#include "MyTcpServer.h"
// #include "database.h"
#include <QApplication>
#include "DatabaseManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    initializeUserDatabase();
    initializeTransactionsDatabase();


    MyTcpServer server;
    if (!server.listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server could not start!";
        return 1;
    } else {
        qDebug() << "Server started!";
    }
    server.onNewConnection();
    server.onReadyRead();

    return a.exec();
}
