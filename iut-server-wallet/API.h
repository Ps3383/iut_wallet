#ifndef API_H
#define API_H

#include <QObject>
#include <QtNetwork>

// class CoinGeckoAPI : public QObject {
//     Q_OBJECT
// public:
//     // CoinGeckoAPI(QObject *parent = nullptr);
//     explicit CoinGeckoAPI(QObject *parent = nullptr);

//     void getCoinDetails(const QString &coinId);
//     void getCurrentPrice(const QString &coinId);
//     void fetchCoinPricesFromAPI();

//     //ADD
// signals:
//     void priceUpdated(const QString &coinId, float price);

// private slots:
//     void onResult(QNetworkReply *reply);

// private:
//     QNetworkAccessManager *manager;
//     QMap<QString, float> prices;

// };

class CoinGeckoAPI : public QObject {
    Q_OBJECT
public:
    explicit CoinGeckoAPI(QObject *parent = nullptr);

    void getCoinDetails(const QString &coinId);
    void getCurrentPrice(const QString &coinId);
    void fetchCoinPricesFromAPI();

signals:
    void priceUpdated(const QString &coinId, float price);

private slots:
    void onResult(QNetworkReply *reply);
    void updatePrices(const QString &coinId, float price);

private:
    QNetworkAccessManager *manager;
    QMap<QString, float> prices;
};

#endif // API_H
