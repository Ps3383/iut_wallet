#ifndef WALLET_H
#define WALLET_H

#include "Coins.h"
#include <string>

class Wallet {
public:
    BTC btc;
    ETH eth;
    TRON trx;
    float USDT;
    std::string email;

    Wallet();
    Wallet(std::string _email);
};

#endif // WALLET_H
