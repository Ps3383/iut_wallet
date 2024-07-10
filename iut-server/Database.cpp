// #include "DatabaseManager.h"
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QJsonDocument>
// #include <QJsonObject>
// #include <QJsonArray>
// #include <QFile>
// #include <QDebug>

// DatabaseManager::DatabaseManager() {
//     db = QSqlDatabase::addDatabase("QSQLITE");
//     db.setDatabaseName("wallets.db");

//     if (!db.open()) {
//         qDebug() << "Error: Could not open database.";
//     }
// }

// void DatabaseManager::createTransactionTable() {
//     QSqlQuery query;
//     QString createTableQuery = R"(
//         CREATE TABLE IF NOT EXISTS transactions (
//             id INTEGER PRIMARY KEY AUTOINCREMENT,
//             type TEXT,
//             email TEXT,
//             source_coin TEXT,
//             destination_coin TEXT,
//             source_address TEXT,
//             destination_address TEXT,
//             source_amount REAL,
//             destination_amount REAL
//         )
//     )";

//     if (!query.exec(createTableQuery)) {
//         qDebug() << "Error creating table: " << query.lastError();
//     }
// }

// void DatabaseManager::insertTransactionFromJson(const QString &jsonFile) {
//     QFile file(jsonFile);
//     if (!file.open(QIODevice::ReadOnly)) {
//         qDebug() << "Could not open file for reading.";
//         return;
//     }

//     QByteArray jsonData = file.readAll();
//     file.close();

//     QJsonDocument doc = QJsonDocument::fromJson(jsonData);
//     if (!doc.isObject()) {
//         qDebug() << "Invalid JSON format.";
//         return;
//     }

//     QJsonObject jsonObj = doc.object();
//     QString type = jsonObj.value("type").toString();
//     QString email = jsonObj.value("email").toString();
//     QString sourceCoin = jsonObj.value("source_coin").toString();
//     QString destinationCoin = jsonObj.value("destination_coin").toString();
//     QString sourceAddress = jsonObj.value("source_address").toString();
//     QString destinationAddress = jsonObj.value("destination_address").toString();
//     float sourceAmount = static_cast<float>(jsonObj.value("source_amount").toDouble());
//     float destinationAmount = static_cast<float>(jsonObj.value("destination_amount").toDouble());

//     QSqlQuery query;
//     query.prepare(R"(
//         INSERT INTO transactions (type, email, source_coin, destination_coin, source_address, destination_address, source_amount, destination_amount)
//         VALUES (:type, :email, :source_coin, :destination_coin, :source_address, :destination_address, :source_amount, :destination_amount)
//     )");

//     query.bindValue(":type", type);
//     query.bindValue(":email", email);
//     query.bindValue(":source_coin", sourceCoin);
//     query.bindValue(":destination_coin", destinationCoin);
//     query.bindValue(":source_address", sourceAddress);
//     query.bindValue(":destination_address", destinationAddress);
//     query.bindValue(":source_amount", sourceAmount);
//     query.bindValue(":destination_amount", destinationAmount);

//     if (!query.exec()) {
//         qDebug() << "Error inserting transaction: " << query.lastError();
//     }
// }
