#ifndef COINS_H
#define COINS_H

#include <string>
#include <unordered_set>
#include <QObject>
#include <QDebug>

class Coin {
public:
    float balance;
    float price;
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

class TRON : public Coin {
public:
    TRON();
    void dummyFunction() override {}
};

// Global variables for coin prices
// extern float BTCPrice;
// extern float ETHPrice;
// extern float TRONPrice;

// void fetchCoinPricesFromAPI(const QString & coinID);

#endif // COINS_H
