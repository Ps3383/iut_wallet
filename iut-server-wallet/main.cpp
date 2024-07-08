#include <QCoreApplication>
#include "Coins.h"
#include "Wallet.h"
#include "DatabaseManager.h"
#include "API.h"
#include <QObject>

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

    // myWallet.btc.balance = 10;
    // myWallet.eth.balance = 20;
    // myWallet.trx.balance = 30;
    // myWallet.USDT = 1000.50f;
    //myWallet.email = "user@example.com";

    DatabaseManager dbManager("wallets.db");
    if (dbManager.isOpen()) {
        dbManager.createTable();
        if (dbManager.addWallet(myWallet)) {
            qDebug() << "Wallet added to the database";
        }
    }

    Wallet retrievedWallet = dbManager.getWallet("user@example.com");

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
     qDebug() << "Words:" << QString::fromStdString(myWallet.word1) << QString::fromStdString(myWallet.word2) << QString::fromStdString(myWallet.word3) << QString::fromStdString(myWallet.word4) << QString::fromStdString(myWallet.word5) << QString::fromStdString(myWallet.word6);

     qDebug() <<"\n\n";

     qDebug() << "Retrieved Wallet:";
     qDebug() << "BTC Balance:" << retrievedWallet.btc.balance;
     qDebug() << "BTC Price:" << retrievedWallet.btc.price;
     qDebug() << "BTC Address:" << QString::fromStdString(retrievedWallet.btc.address);

     qDebug() << "ETH Balance:" << retrievedWallet.eth.balance;
     qDebug() << "ETH Price:" << retrievedWallet.eth.price;
     qDebug() << "ETH Address:" << QString::fromStdString(retrievedWallet.eth.address);

     qDebug() << "TRON Balance:" << retrievedWallet.trx.balance;
     qDebug() << "TRON Price:" << retrievedWallet.trx.price;
     qDebug() << "TRON Address:" << QString::fromStdString(retrievedWallet.trx.address);

     qDebug() << "USDT:" << retrievedWallet.USDT;
     qDebug() << "Email:" << QString::fromStdString(retrievedWallet.email);

     qDebug() << "Words:" << QString::fromStdString(retrievedWallet.word1) << QString::fromStdString(retrievedWallet.word2) << QString::fromStdString(retrievedWallet.word3) << QString::fromStdString(retrievedWallet.word4) << QString::fromStdString(retrievedWallet.word5) << QString::fromStdString(retrievedWallet.word6);

    return a.exec();
}
