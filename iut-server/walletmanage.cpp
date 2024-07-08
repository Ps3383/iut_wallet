#include "walletmanage.h"
#include "ui_walletmanage.h"

wallet::wallet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wallet)
{
    ui->setupUi(this);
}

wallet::~wallet()
{
    delete ui;
}

wallet::wallet(QObject* parent) : QObject(parent) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("wallets.db");

    if (!db.open()) {
        qDebug() << "Database error occurred:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS wallets (email TEXT, walletName TEXT, seedPhrase TEXT, balance REAL)");
        query.exec("CREATE TABLE IF NOT EXISTS addresses (email TEXT, walletName TEXT, address TEXT)");
        query.exec("CREATE TABLE IF NOT EXISTS transactions (email TEXT, walletName TEXT, type TEXT, amount REAL, date TEXT)");
    }
}

void wallet::createWallet(const QString& email, const QString& walletName) {
    QString seedPhrase = generateSeedPhrase();

    QSqlQuery query;
    query.prepare("INSERT INTO wallets (email, walletName, seedPhrase, balance) VALUES (:email, :walletName, :seedPhrase, 0.0)");
    query.bindValue(":email", email);
    query.bindValue(":walletName", walletName);
    query.bindValue(":seedPhrase", seedPhrase);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
        emit walletCreated("Error");
    } else {
        qDebug() << "Wallet created successfully";
        emit walletCreated(seedPhrase);
    }
}

void wallet::getBalance(const QString& email, const QString& walletName) {
    QSqlQuery query;
    query.prepare("SELECT balance FROM wallets WHERE email = :email AND walletName = :walletName");
    query.bindValue(":email", email);
    query.bindValue(":walletName", walletName);

    if (!query.exec() || !query.next()) {
        qDebug() << "Wallet not found";
        emit balanceFetched(QJsonObject());
    } else {
        double balance = query.value(0).toDouble();
        QJsonObject response;
        response["balance"] = balance;
        emit balanceFetched(response);
    }
}

void wallet::generateAddress(const QString& email, const QString& walletName) {
    QString address = generateUniqueAddress();

    QSqlQuery query;
    query.prepare("INSERT INTO addresses (email, walletName, address) VALUES (:email, :walletName, :address)");
    query.bindValue(":email", email);
    query.bindValue(":walletName", walletName);
    query.bindValue(":address", address);

    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
        emit addressGenerated(QJsonObject());
    } else {
        qDebug() << "Address generated successfully";
        QJsonObject response;
        response["address"] = address;
        emit addressGenerated(response);
    }
}

void wallet::getTransactionHistory(const QString& email, const QString& walletName) {
    QSqlQuery query;
    query.prepare("SELECT type, amount, date FROM transactions WHERE email = :email AND walletName = :walletName");
    query.bindValue(":email", email);
    query.bindValue(":walletName", walletName);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        emit transactionHistoryFetched(QJsonArray());
    } else {
        QJsonArray response;
        while (query.next()) {
            QJsonObject transaction;
            transaction["type"] = query.value(0).toString();
            transaction["amount"] = query.value(1).toDouble();
            transaction["date"] = query.value(2).toString();
            response.append(transaction);
        }
        emit transactionHistoryFetched(response);
    }
}

QString wallet::generateSeedPhrase() {
    // Generate a 12-word seed phrase
    // This is a placeholder implementation. You should use a proper seed phrase generator.
    return "word1 word2 word3 word4 word5 word6 word7 word8 word9 word10 word11 word12";
}

QString wallet::generateUniqueAddress() {
    // Generate a unique address
    // This is a placeholder implementation. You should use a proper address generator.
    return "unique-address";
}
