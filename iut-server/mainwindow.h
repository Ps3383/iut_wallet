#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>
#include <QList>

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

private slots:
    void on_pushButton_clicked();
public slots:
    void server_newconnection ();
    void socket_connected();
    void socket_readyRead(QTcpSocket *_socket);
    void socket_bytesWritten(QTcpSocket *_socket);
    void socket_disconnected(QTcpSocket *_socket);
private:
    Ui::MainWindow *ui;
    QTcpServer *myserver=nullptr;
    QList<QTcpSocket*>clients;
};
#endif // MAINWINDOW_H
