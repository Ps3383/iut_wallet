#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVariantList>
#include "Wallet.h"

class DatabaseManager {
public:
    DatabaseManager(const QString &path);
    ~DatabaseManager();

    bool isOpen() const;
    bool createTable();
    bool addWallet(const Wallet &wallet);
    Wallet getWallet(const QString &email);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
