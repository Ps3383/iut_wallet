#include <QCoreApplication>
#include "Coins.h"
#include "Wallet.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Fetch the latest coin prices from the API
    fetchCoinPricesFromAPI();

    CoinGeckoAPI api;
    api.getCoinDetails("bitcoin");
    api.getCurrentPrice("ethereum");

    Wallet myWallet("mahdi@gmail.com");


    myWallet.btc.balance = 10;
    myWallet.eth.balance = 20;
    myWallet.ton.balance = 30;
    myWallet.USDT = 1000.50f;
    //myWallet.email = "user@example.com";

    // Printing values
    qDebug() << "BTC Balance:" << myWallet.btc.balance;
    qDebug() << "BTC Price:" << myWallet.btc.price;
    qDebug() << "BTC Address:" << QString::fromStdString(myWallet.btc.address);

    qDebug() << "ETH Balance:" << myWallet.eth.balance;
    qDebug() << "ETH Price:" << myWallet.eth.price;
    qDebug() << "ETH Address:" << QString::fromStdString(myWallet.eth.address);

    qDebug() << "TON Balance:" << myWallet.ton.balance;
    qDebug() << "TON Price:" << myWallet.ton.price;
    qDebug() << "TON Address:" << QString::fromStdString(myWallet.ton.address);

    qDebug() << "USDT:" << myWallet.USDT;
    qDebug() << "Email:" << QString::fromStdString(myWallet.email);

    return a.exec();
}
