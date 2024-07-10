#include "Database.h"
#include <QDebug>
#include <QJsonArray>

DatabaseManager::DatabaseManager(const QString &path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }
}

DatabaseManager::~DatabaseManager() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::isOpen() const {
    return m_db.isOpen();
}

bool DatabaseManager::createTable() {
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS wallets ("
                  "email TEXT PRIMARY KEY, "
                  "btc_balance REAL, btc_price REAL, btc_address TEXT, "
                  "eth_balance REAL, eth_price REAL, eth_address TEXT, "
                  "trx_balance REAL, trx_price REAL, trx_address TEXT, "
                  "usdt REAL, "
                  "word1 TEXT, word2 TEXT, word3 TEXT, word4 TEXT, word5 TEXT, word6 TEXT);");

    if (!query.exec()) {
        qDebug() << "Couldn't create the table 'wallets': one might already exist.";
        success = false;
    } else {
        success = true;
    }

    return success;
}

bool DatabaseManager::addWallet(const Wallet &wallet) {
    bool success = false;

    QSqlQuery query;
    query.prepare("INSERT INTO wallets (email, btc_balance, btc_price, btc_address, eth_balance, eth_price, eth_address, trx_balance, trx_price, trx_address, usdt, word1, word2, word3, word4, word5, word6) "
                  "VALUES (:email, :btc_balance, :btc_price, :btc_address, :eth_balance, :eth_price, :eth_address, :trx_balance, :trx_price, :trx_address, :usdt, :word1, :word2, :word3, :word4, :word5, :word6)");

    query.bindValue(":email", wallet.email);
    query.bindValue(":btc_balance", wallet.btc.balance);
    query.bindValue(":btc_price", wallet.btc.price);
    query.bindValue(":btc_address", QString::fromStdString(wallet.btc.address));
    query.bindValue(":eth_balance", wallet.eth.balance);
    query.bindValue(":eth_price", wallet.eth.price);
    query.bindValue(":eth_address", QString::fromStdString(wallet.eth.address));
    query.bindValue(":trx_balance", wallet.trx.balance);
    query.bindValue(":trx_price", wallet.trx.price);
    query.bindValue(":trx_address", QString::fromStdString(wallet.trx.address));
    query.bindValue(":usdt", wallet.USDT);
    query.bindValue(":word1", QString::fromStdString(wallet.word1));
    query.bindValue(":word2", QString::fromStdString(wallet.word2));
    query.bindValue(":word3", QString::fromStdString(wallet.word3));
    query.bindValue(":word4", QString::fromStdString(wallet.word4));
    query.bindValue(":word5", QString::fromStdString(wallet.word5));
    query.bindValue(":word6", QString::fromStdString(wallet.word6));

    if (query.exec()) {
        success = true;
    } else {
        qDebug() << "addWallet error: " << query.lastError();
    }

    return success;
}

QJsonObject DatabaseManager::getWallet(const QString &email, const QString &name) const{
    QJsonObject jsonObj;

    QSqlQuery query;
    query.prepare("SELECT * FROM wallets WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.next()) {
            jsonObj["status"] = "success";
            jsonObj["email"] = query.value("email").toString();
            jsonObj["btc_balance"] = query.value("btc_balance").toInt();
            jsonObj["btc_price"] = query.value("btc_price").toInt();
            jsonObj["btc_address"] = query.value("btc_address").toString();
            jsonObj["eth_balance"] = query.value("eth_balance").toInt();
            jsonObj["eth_price"] = query.value("eth_price").toInt();
            jsonObj["eth_address"] = query.value("eth_address").toString();
            jsonObj["trx_balance"] = query.value("trx_balance").toInt();
            jsonObj["trx_price"] = query.value("trx_price").toInt();
            jsonObj["trx_address"] = query.value("trx_address").toString();
            jsonObj["usdt"] = query.value("usdt").toFloat();

            QJsonArray wordsArray;
            wordsArray.append(query.value("word1").toString());
            wordsArray.append(query.value("word2").toString());
            wordsArray.append(query.value("word3").toString());
            wordsArray.append(query.value("word4").toString());
            wordsArray.append(query.value("word5").toString());
            wordsArray.append(query.value("word6").toString());

            jsonObj["words"] = wordsArray;

            return jsonObj;
        }
        qDebug() << "Invalid input";
    }
    qDebug() << "Select error:" << query.lastError().text();
    jsonObj["status"] = "failed";
    return jsonObj;
}


void initializeUserDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "email TEXT, "
               "password TEXT, "
               "name TEXT, "
               "address TEXT, "
               "phoneNumber TEXT)");
}

void initializeTransactionsDatabase() {
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("transactions.db");

    if (!db2.open()) {
        qDebug() << "Cannot open database:" << db2.lastError().text();
        return;
    }

    QSqlQuery query1;
    query1.exec("CREATE TABLE IF NOT EXISTS transactions ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "sellORbuy TEXT,"
               "email TEXT,"
               "source_coin TEXT,"
               "destination_coin TEXT, "
               "source_address TEXT, "
               "destination_address TEXT, "
               "source_amount REAL, "
               "destination_amount REAL)");
}

