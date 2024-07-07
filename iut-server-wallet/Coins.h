#ifndef COINS_H
#define COINS_H

#include <string>
#include <unordered_set>
#include <QObject>
#include <QtNetwork>
#include <QDebug>

class CoinGeckoAPI : public QObject {
    Q_OBJECT
public:
    CoinGeckoAPI(QObject *parent = nullptr);

    void getCoinDetails(const QString &coinId);
    void getCurrentPrice(const QString &coinId);

private slots:
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};

class Coin {
public:
    int balance;
    int price;
    std::string address;

    Coin();
    virtual ~Coin() = default;

    // Making the base class abstract by declaring a pure virtual function
    virtual void dummyFunction() = 0;

private:
    static std::unordered_set<std::string> usedAddresses;
    std::string generateUniqueAddress();
};

// Derived Classes
class BTC : public Coin {
public:
    BTC();
    void dummyFunction() override {}
};

class ETH : public Coin {
public:
    ETH();
    void dummyFunction() override {}
};

class TON : public Coin {
public:
    TON();
    void dummyFunction() override {}
};

// Global variables for coin prices
extern int BTCPrice;
extern int ETHPrice;
extern int TONPrice;

void fetchCoinPricesFromAPI();

#endif // COINS_H
