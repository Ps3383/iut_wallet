#include "DatabaseManager.h"
#include <QDebug>

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
                  "btc_balance INTEGER, btc_price INTEGER, btc_address TEXT, "
                  "eth_balance INTEGER, eth_price INTEGER, eth_address TEXT, "
                  "trx_balance INTEGER, trx_price INTEGER, trx_address TEXT, "
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

    query.bindValue(":email", QString::fromStdString(wallet.email));
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

Wallet DatabaseManager::getWallet(const QString &email) {
    QSqlQuery query;
    query.prepare("SELECT * FROM wallets WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.next()) {
            Wallet wallet;
            wallet.email = query.value("email").toString().toStdString();
            wallet.btc.balance = query.value("btc_balance").toInt();
            wallet.btc.price = query.value("btc_price").toInt();
            wallet.btc.address = query.value("btc_address").toString().toStdString();
            wallet.eth.balance = query.value("eth_balance").toInt();
            wallet.eth.price = query.value("eth_price").toInt();
            wallet.eth.address = query.value("eth_address").toString().toStdString();
            wallet.trx.balance = query.value("trx_balance").toInt();
            wallet.trx.price = query.value("trx_price").toInt();
            wallet.trx.address = query.value("trx_address").toString().toStdString();
            wallet.USDT = query.value("usdt").toFloat();
            const_cast<std::string&>(wallet.word1) = query.value("word1").toString().toStdString();
            const_cast<std::string&>(wallet.word2) = query.value("word2").toString().toStdString();
            const_cast<std::string&>(wallet.word3) = query.value("word3").toString().toStdString();
            const_cast<std::string&>(wallet.word4) = query.value("word4").toString().toStdString();
            const_cast<std::string&>(wallet.word5) = query.value("word5").toString().toStdString();
            const_cast<std::string&>(wallet.word6) = query.value("word6").toString().toStdString();
            return wallet;
        }
    }

    return Wallet();
}
