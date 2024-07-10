#ifndef WALLET_H
#define WALLET_H

#include "coins.h"
#include <string>
#include <array>
#include <unordered_set>

class Wallet {
public:
    BTC btc;
    ETH eth;
    TRON trx;
    float USDT;
    QString email;
    QString walletName;
    const std::string word1;
    const std::string word2;
    const std::string word3;
    const std::string word4;
    const std::string word5;
    const std::string word6;

    Wallet();
    Wallet(QString _email, QString _name);

private:
    static std::unordered_set<std::array<std::string, 6>> usedWords;
    std::array<std::string, 6> generateUniqueWords() const;
    std::string getRandomWord() const;
};

#endif // WALLET_H
