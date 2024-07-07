#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class signinpage;
}

class signinpage : public QDialog
{
    Q_OBJECT

public:
    explicit signinpage(QWidget *parent = nullptr);
    ~signinpage();
    void setupconnection();

private slots:
    void on_pushButton_2_clicked();
    void on_login_clicked();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError socketError);


private:
    Ui::signinpage *ui;
    QTcpSocket *ssocket; // اضافه کردن سوکت
};

#endif // SIGNINPAGE_H
