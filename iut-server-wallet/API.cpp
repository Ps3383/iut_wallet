#include "API.h"

QMap<QString, float> prices;

// Constructor implementation
CoinGeckoAPI::CoinGeckoAPI(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &CoinGeckoAPI::onResult);
    // connect(this, &CoinGeckoAPI::priceUpdated, this, &CoinGeckoAPI::updatePrices);
}
// CoinGeckoAPI::CoinGeckoAPI(QObject *parent) : QObject(parent) {
//     manager = new QNetworkAccessManager(this);
//     connect(manager, &QNetworkAccessManager::finished, this, &CoinGeckoAPI::onResult);
// }

// void CoinGeckoAPI::updatePrices(const QString &coinId, float price) {
//     if (coinId == "bitcoin") {
//         BTCPrice = price;
//     } else if (coinId == "ethereum") {
//         ETHPrice = price;
//     } else if (coinId == "tron") {
//         TRONPrice = price;
//     }
//     qDebug() << coinId << "price updated to:" << price;
// }

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

        QStringList coinIds = {"bitcoin", "ethereum", "notcoin", "tron", "solana"};
        for (const QString &coinId : coinIds) {
            if (jsonObject.contains(coinId) && jsonObject[coinId].isObject()) {
                QJsonObject coinObject = jsonObject[coinId].toObject();
                if (coinObject.contains("usd") && coinObject["usd"].isDouble()) {
                    double price = coinObject["usd"].toDouble();
                    float priceInFloat = static_cast<float>(price);
                    prices[coinId] = priceInFloat;
                    qDebug()<< coinId << "price save on map:" << prices[coinId];
                    // emit priceUpdated(coinId, priceInFloat);
                }
            }
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}
// void CoinGeckoAPI::fetchCoinPricesFromAPI() {

//     // price for COINS
//     BTCPrice = prices["bitcoin"];
//     qDebug()<< "BTCPrice:" << prices["bitcoin"];
//     ETHPrice = prices["ethereum"];
//     qDebug()<< "ETHPrice:" << prices["ethereum"];
//     TRONPrice = prices["tron"];
//     qDebug()<< "TRONPrice:" << prices["tron"];

// }

void CoinGeckoAPI::fetchCoinPricesFromAPI() {
    qDebug() << "Fetching prices:";
    getCurrentPrice("bitcoin");
    getCurrentPrice("ethereum");
    getCurrentPrice("tron");
}
