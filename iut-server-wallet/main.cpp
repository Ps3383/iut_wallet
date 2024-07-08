#include <QCoreApplication>
#include "Coins.h"
#include "Wallet.h"
#include "API.h"

#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CoinGeckoAPI api;
    api.fetchCoinPricesFromAPI();
    //add
    // QObject::connect(&api, &CoinGeckoAPI::priceUpdated, [](const QString &coinId, float price) {
    //     qDebug() << "Price of" << coinId << "updated to" << price;
    // });


    // api.getCoinDetails("bitcoin");
    // api.getCurrentPrice("ethereum");
    // api.getCurrentPrice("bitcoin");
    // api.getCurrentPrice("tron");
    // api.getCurrentPrice("notcoin");
    // api.getCurrentPrice("solana");
    // api.fetchCoinPricesFromAPI();
    QThread::msleep(2000);

    Wallet myWallet("mahdi@gmail.com");

    myWallet.btc.balance = 10;
    myWallet.eth.balance = 20;
    myWallet.trx.balance = 30;
    myWallet.USDT = 1000.50f;
    //myWallet.email = "user@example.com";

    // Printing values
     qDebug() << "BTC Balance:" << myWallet.btc.balance;
     qDebug() << "BTC Price:" << myWallet.btc.price;
     qDebug() << "BTC Address:" << QString::fromStdString(myWallet.btc.address);

     qDebug() << "ETH Balance:" << myWallet.eth.balance;
     qDebug() << "ETH Price:" << myWallet.eth.price;
     qDebug() << "ETH Address:" << QString::fromStdString(myWallet.eth.address);

     qDebug() << "TRON Balance:" << myWallet.trx.balance;
     qDebug() << "TRON Price:" << myWallet.trx.price;
     qDebug() << "TRON Address:" << QString::fromStdString(myWallet.trx.address);

     qDebug() << "USDT:" << myWallet.USDT;
     qDebug() << "Email:" << QString::fromStdString(myWallet.email);

    return a.exec();
}
