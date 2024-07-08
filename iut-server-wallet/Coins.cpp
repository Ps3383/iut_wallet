#include "Coins.h"
#include "API.h"
#include <random>
#include <ctime>
#include <unordered_set>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QMap>

std::unordered_set<std::string> Coin::usedAddresses;

// float BTCPrice = 0;
// float ETHPrice = 0;
// float TRONPrice = 0;

Coin::Coin() {
    address = generateUniqueAddress();
}

std::string Coin::generateUniqueAddress() {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static std::mt19937 rng(std::time(nullptr));

    std::string newAddress;
    do {
        newAddress.clear();
        for (int i = 0; i < 12; ++i) {
            newAddress += alphanum[rng() % (sizeof(alphanum) - 1)];
        }
    } while (usedAddresses.find(newAddress) != usedAddresses.end());

    usedAddresses.insert(newAddress);
    return newAddress;
}

BTC::BTC() {
    price = prices["bitcoin"];
    address += "BTC";
    qDebug()<< "BTCprice in constructor = " <<prices["bitcoin"];
}

ETH::ETH() {
    price = prices["ethereum"];
    address += "ETH";
    qDebug()<< "ETHprice in constructor = " <<prices["ethereum"];
}

TRON::TRON() {
    price = prices["tron"];
    address += "TRON";
    qDebug()<< "TRONprice in constructor = " <<prices["tron"];
}

// void fetchCoinPricesFromAPI() {

//   // Example price for COINS
//     BTCPrice = 55000;
//     ETHPrice = 7000;
//     TONPrice = 7;

// }

// void CoinGeckoAPI::onResult(QNetworkReply *reply) {
//     if (reply->error() == QNetworkReply::NoError) {
//         QByteArray responseData = reply->readAll();
//         QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
//         QJsonObject jsonObject = jsonResponse.object();
//         qDebug() << jsonObject;
//     } else {
//         qDebug() << "Error:" << reply->errorString();
//     }
//     reply->deleteLater();
// }
