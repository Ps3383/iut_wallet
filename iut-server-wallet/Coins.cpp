#include "Coins.h"
#include <random>
#include <ctime>
//#include <iostream>
#include <unordered_set>
#include <QJsonDocument>
#include <QJsonObject>
//#include <QDebug>

std::unordered_set<std::string> Coin::usedAddresses;

int BTCPrice = 0;
int ETHPrice = 0;
int TONPrice = 0;

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
    price = BTCPrice;
    address += "BTC";
}

ETH::ETH() {
    price = ETHPrice;
    address += "ETH";
}

TON::TON() {
    price = TONPrice;
    address += "TON";
}

void fetchCoinPricesFromAPI() {

  // Example price for COINS
    BTCPrice = 30000;
    ETHPrice = 2000;
    TONPrice = 5;

}

CoinGeckoAPI::CoinGeckoAPI(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &CoinGeckoAPI::onResult);
}

void CoinGeckoAPI::getCoinDetails(const QString &coinId) {
    QUrl url("https://api.coingecko.com/api/v3/coins/" + coinId);
    QNetworkRequest request(url);
    manager->get(request);
}

void CoinGeckoAPI::getCurrentPrice(const QString &coinId) {
    QUrl url("https://api.coingecko.com/api/v3/simple/price?ids=" + coinId + "&vs_currencies=usd");
    QNetworkRequest request(url);
    manager->get(request);
}

void CoinGeckoAPI::onResult(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();
        qDebug() << jsonObject;
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}
