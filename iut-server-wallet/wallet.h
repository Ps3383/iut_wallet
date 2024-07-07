#ifndef WALLET_H
#define WALLET_H

#include <QMainWindow>

class Wallet : public QMainWindow
{
    Q_OBJECT

public:
    Wallet(QWidget *parent = nullptr);
    ~Wallet();
};
#endif // WALLET_H
