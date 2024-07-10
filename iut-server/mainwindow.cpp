#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    if(myserver!=nullptr){
        //ui->textBrowser->append("alredy connected");
        qDebug()<< "already coonected ";
    }
    else{
        //ui->textBrowser->append("connecting");
        qDebug()<< "connecting";
        myserver = new QTcpServer();
        myserver->listen(QHostAddress::Any, 1027);

        if(myserver->isListening()){
            connect(myserver,SIGNAL(newConnection()),this,SLOT(server_newconnection()));
            //ui->textBrowser->append("connected");
            qDebug()<< "coonected ";
        }
    }
}

void MainWindow::server_newconnection(){
    QTcpSocket * new_client= myserver->nextPendingConnection();
    new_client->setObjectName("client"+QString::number(clients.size() + 1));
    clients.append(new_client);

    connect(new_client,SIGNAL(connected()),this,SLOT(socket_connected()));
    connect(new_client,&QAbstractSocket::disconnected,this,[this, new_client](){ socket_disconnected(new_client); });
    connect(new_client,&QIODevice::readyRead,this, [this, new_client](){ socket_readyRead(new_client); });
    connect(new_client, &QIODevice::bytesWritten,this,[this, new_client](){ socket_bytesWritten(new_client); });
   /// ui->textBrowser->append("new client connected");
}

void MainWindow::socket_connected(){
   // ui->textBrowser->append("connected");
    qDebug()<< "coonected ";
}
void MainWindow::socket_readyRead(QTcpSocket *_socket){
    QByteArray data = _socket->readAll();
   // ui->textBrowser->append("" + _socket->objectName() + ": " + data);
    QString message_back_to_client = "Got your message!" + _socket->readAll() + "";
    _socket->write(message_back_to_client.toUtf8());
    _socket->flush();
    _socket->waitForBytesWritten(3000);
}
void MainWindow::socket_bytesWritten(QTcpSocket *_socket){
   // ui->textBrowser->append("data was written");
    qDebug()<< "data was written ";

}
void MainWindow::socket_disconnected(QTcpSocket *_socket){
    //ui->textBrowser->append(_socket->objectName()+"disconnect");
    clients.removeOne(_socket);

    for(int i =0 ; i<clients.size();++i){
        clients[i]->setObjectName("Client " + QString::number(i + 1));
    }

    _socket->deleteLater();
}


