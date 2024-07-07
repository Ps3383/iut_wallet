#include "mainwindow.h"
#include "MyTcpServer.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     MainWindow w;
    initializeDatabase();

    MyTcpServer server;
    if (!server.listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server could not start!";
        return 1;
    } else {
        qDebug() << "Server started!";
    }
    w.show();



    return a.exec();
}
