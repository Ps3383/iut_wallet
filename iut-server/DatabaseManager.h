#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "Wallet.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVariantList>
#include <QJsonObject>
#include <QJsonDocument>

class DatabaseManager {
public:
    DatabaseManager(const QString &path);
    ~DatabaseManager();

    bool isOpen() const;
    bool createTable();
    bool addWallet(const Wallet &wallet);
    // Wallet getWallet(const QString &email);
    QJsonObject getWallet(const QString &email, const QString &name) const;
    // QJsonObject toJson() const;

private:
    QSqlDatabase m_db;
};
void initializeUserDatabase();
void initializeTransactionsDatabase();

#endif // DATABASEMANAGER_H
