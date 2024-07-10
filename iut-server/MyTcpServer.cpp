#include "MyTcpServer.h"
#include"Database.h"
MyTcpServer::MyTcpServer(QObject* parent) : QTcpServer(parent) {
    connect(this, &QTcpServer::newConnection, this, &MyTcpServer::onNewConnection);
}

void MyTcpServer::onNewConnection() {
    QTcpSocket* socket = nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::onReadyRead);
}

void MyTcpServer::onReadyRead() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    QByteArray data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
	if (doc.isNull()) {
        qDebug() << "Invalid JSON received";
        socket->write("Invalid JSON");
        socket->flush();
        socket->close();
        return;
    }
    QJsonObject json = doc.object();
	qDebug() << "Received JSON:" << doc.toJson(QJsonDocument::Indented);


    QString type = json["type"].toString();

    if(type=="signup"){

        QString email = json["email"].toString();
        QString password = json["password"].toString();
        QString name = json["name"].toString();
        QString address = json["address"].toString();
        QString phoneNumber = json["phoneNumber"].toString();

        // Check for duplicate email
        initializeUserDatabase();
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM users WHERE email = :email");
        checkQuery.bindValue(":email", email);

        if (!checkQuery.exec()) {
            qDebug() << "Check query error:" << checkQuery.lastError().text();
            socket->write("Error");
            socket->flush();
            socket->close();
            return;
        }

        checkQuery.next();
        if (checkQuery.value(0).toInt() > 0) {
            qDebug() << "Email already exists";
            socket->write("Email already exists");
            socket->flush();
            socket->close();
            return;
        }

        // Check for duplicate password
        checkQuery.prepare("SELECT COUNT(*) FROM users WHERE password = :password");
        checkQuery.bindValue(":password", password);

        if (!checkQuery.exec()) {
            qDebug() << "Check query error:" << checkQuery.lastError().text();
            socket->write("Error");
            socket->flush();
            socket->close();
            return;
        }

        checkQuery.next();
        if (checkQuery.value(0).toInt() > 0) {
            qDebug() << "Password already exists";
            socket->write("Password already exists");
            socket->flush();
            socket->close();
            return;
        }
        QSqlQuery query;
        query.prepare("INSERT INTO users (email, password, name, address, phoneNumber) VALUES (:email, :password, :name, :address, :phoneNumber)");
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        query.bindValue(":name", name);
        query.bindValue(":address", address);
        query.bindValue(":phoneNumber", phoneNumber);

        if (!query.exec()) {
            qDebug() << "Insert error:" << query.lastError().text();
            socket->write("Error");
        }
        else {
            qDebug() << "Data inserted successfully";
            socket->write("Success");
        }
    }
    else if (type == "signin") {
        QString email = json["email"].toString();
        QString password = json["password"].toString();
        initializeUserDatabase();
        QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE email = :email AND password = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", password);
        if (!query.exec()) {
            qDebug() << "Select error:" << query.lastError().text();
            socket->write("Error");
        } else {
            if (query.next()) {
                qDebug() << "User exists";
                socket->write("User exists");
            } else {
                qDebug() << "Invalid credentials";
                socket->write("Invalid credentials");
            }
        }
    }

    else if (type == "change_password") {
        QString email = json["email"].toString();
        QString newPassword = json["new_password"].toString();


        // // Check for duplicate password
        // QSqlQuery checkQuery;

        // checkQuery.prepare("SELECT COUNT(*) FROM users WHERE password = :password");
        // checkQuery.bindValue(":password", newPassword);

        // if (!checkQuery.exec()) {
        //     qDebug() << "Check query error:" << checkQuery.lastError().text();
        //     socket->write("Error");
        //     socket->flush();
        //     socket->close();
        //     return;
        // }

        // checkQuery.next();
        // if (checkQuery.value(0).toInt() > 0) {
        //     qDebug() << "pass exists";
        //     socket->write("pass exists");
        //     socket->flush();
        //     socket->close();
        //     return;
        // }
        initializeUserDatabase();
        QSqlQuery query;
        query.prepare("UPDATE users SET password = :new_password WHERE email = :email");
        query.bindValue(":email", email);
        query.bindValue(":new_password", newPassword);

        if (!query.exec()) {
            qDebug() << "Password update error:" << query.lastError().text();
            socket->write("Error");
        }
        else {
            qDebug() << "Password updated successfully";
            socket->write("Success");
        }
    }



    else if (type == "change_phone_number") {
        QString email = json["email"].toString();
        QString newPhoneNumber = json["new_phone_number"].toString();
        initializeUserDatabase();
        QSqlQuery query;
        query.prepare("UPDATE users SET phoneNumber = :phoneNumber WHERE email = :email");
        query.bindValue(":phoneNumber", newPhoneNumber);
        query.bindValue(":email", email);

        if (!query.exec()) {
            qDebug() << "Update error:" << query.lastError().text();
            socket->write("Error");
        } else {
            qDebug() << "Phone number updated successfully";
            socket->write("Success");
        }
    }

    else if (type == "change_address") {
        QString email = json["email"].toString();
        QString newAddress = json["new_address"].toString();
initializeUserDatabase();
        QSqlQuery query;
        query.prepare("UPDATE users SET address = :address WHERE email = :email");
        query.bindValue(":address", newAddress);
        query.bindValue(":email", email);

        if (!query.exec()) {
            qDebug() << "Update error:" << query.lastError().text();
            socket->write("Error");
        } else {
            qDebug() << "Address updated successfully";
            socket->write("Success");
        }
    }
    else if (type == "change_name") {
        QString email = json["email"].toString();
        QString newName = json["new_name"].toString();
initializeUserDatabase();
        QSqlQuery query;
        query.prepare("UPDATE users SET name = :name WHERE email = :email");
        query.bindValue(":name", newName);
        query.bindValue(":email", email);

        if (!query.exec()) {
            qDebug() << "Update error:" << query.lastError().text();
            socket->write("Error");
        } else {
            qDebug() << "Name updated successfully";
            socket->write("Success");
        }
    }

    else if(type == "getWallet"){

        QString email = json["email"].toString();
        QString name = json["walletName"].toString();

        DatabaseManager dbManager("wallets.db");
        QJsonObject json = dbManager.getWallet(email, name);

        QJsonDocument doc(json);
        QByteArray data = doc.toJson();


        socket->write(data);
        socket->flush();
        qDebug() << "data was sent to client";
    }
    else if (type == "addWallet"){

        QString email = json["email"].toString();
        QString name = json["walletName"].toString();

        Wallet myWallet(email, name);

        DatabaseManager dbManager("wallets.db");
        if (dbManager.isOpen()) {
            dbManager.createTable();
            if (dbManager.addWallet(myWallet)) {
                qDebug() << "Wallet added to the database";
            }
        }
    }
    else if(type == "transactions"){
        //open and initial transactions.db database
        initializeTransactionsDatabase();
        QString transactionType = json.value("sellORbuy").toString();
        QString email = json.value("email").toString();
        QString sourceCoin = json.value("source_coin").toString();
        QString destinationCoin = json.value("destination_coin").toString();
        QString sourceAddress = json.value("source_address").toString();
        QString destinationAddress = json.value("destination_address").toString();
        float sourceAmount = static_cast<float>(json.value("source_amount").toDouble());
        float destinationAmount = static_cast<float>(json.value("destination_amount").toDouble());

        QSqlQuery query;
        query.prepare("INSERT INTO transactions (sellORbuy, email, source_coin, destination_coin, source_address, destination_address, source_amount, destination_amount ) VALUES (:sellORbuy, :email, :source_coin, :destination_coin, :source_address, :destination_address, :source_amount, :destination_amount)");
        query.bindValue(":sellORbuy", transactionType);
        query.bindValue(":email", email);
        query.bindValue(":source_coin", sourceCoin);
        query.bindValue(":destination_coin", destinationCoin);
        query.bindValue(":source_address", sourceAddress);
        query.bindValue(":destination_address", destinationAddress);
        query.bindValue(":source_amount", sourceAmount);
        query.bindValue(":destination_amount", destinationAmount);

        if (!query.exec()) {
            qDebug() << "Transactions insert error:" << query.lastError().text();
            socket->write("Error");
        } else {
            qDebug() << "Transactions inserted successfully";
            socket->write("Success");
        }

        //***************************************************************add wallet Obj query *******************************************************************
        //open and initial wallets.db database
        DatabaseManager dbManager("wallets.db");
        if (dbManager.isOpen()) {
            dbManager.createTable();
            QSqlQuery selectQuery;
            QSqlQuery updateQuery;

            // for buy transaction
            if (transactionType == "buy") {
                if (destinationCoin == "btc") {
                    selectQuery.prepare("SELECT usdt FROM wallets WHERE email = :email");
                    selectQuery.bindValue(":email", email);
                    if (selectQuery.exec() && selectQuery.next()) {
                        float currentUSDT = selectQuery.value(0).toFloat();
                        if (currentUSDT < sourceAmount) {
                            qDebug() << "Insufficient USDT balance";
                            socket->write("Insufficient USDT balance");
                            return;
                        }
                    }
                    updateQuery.prepare("UPDATE wallets SET btc_balanc = btc_balanc + :destination_amount, usdt = usdt - :source_amount WHERE email = :email");
                } else if (destinationCoin == "eth") {
                    selectQuery.prepare("SELECT usdt FROM wallets WHERE email = :email");
                    selectQuery.bindValue(":email", email);
                    if (selectQuery.exec() && selectQuery.next()) {
                        float currentUSDT = selectQuery.value(0).toFloat();
                        if (currentUSDT < sourceAmount) {
                            qDebug() << "Insufficient USDT balance";
                            socket->write("Insufficient USDT balance");
                            return;
                        }
                    }
                    updateQuery.prepare("UPDATE wallets SET eth_balanc = eth_balanc + :destination_amount, usdt = usdt - :source_amount WHERE email = :email");
                } else if (destinationCoin == "trx") {
                    selectQuery.prepare("SELECT usdt FROM wallets WHERE email = :email");
                    selectQuery.bindValue(":email", email);
                    if (selectQuery.exec() && selectQuery.next()) {
                        float currentUSDT = selectQuery.value(0).toFloat();
                        if (currentUSDT < sourceAmount) {
                            qDebug() << "Insufficient USDT balance";
                            socket->write("Insufficient USDT balance");
                            return;
                        }
                    }
                    updateQuery.prepare("UPDATE wallets SET trx_balanc = trx_balanc + :destination_amount, usdt = usdt - :source_amount WHERE email = :email");
                }
                updateQuery.bindValue(":destination_amount", destinationAmount);
                updateQuery.bindValue(":source_amount", sourceAmount);
                updateQuery.bindValue(":email", email);

                if (!updateQuery.exec()) {
                    qDebug() << "Coin wasn't bought" << updateQuery.lastError().text();
                    socket->write("Error");
                } else {
                    qDebug() << "Coin was bought";
                    socket->write("Success");
                }
            }
            else if (transactionType == "sell") {
                if (destinationCoin == "btc") {
                    selectQuery.prepare("SELECT btc_balanc FROM wallets WHERE email = :email");
                    selectQuery.bindValue(":email", email);
                    if (selectQuery.exec() && selectQuery.next()) {
                        float currentBTC = selectQuery.value(0).toFloat();
                        if (currentBTC < sourceAmount) {
                            qDebug() << "Insufficient BTC balance";
                            socket->write("Insufficient BTC balance");
                            return;
                        }
                    }
                    updateQuery.prepare("UPDATE wallets SET btc_balanc = btc_balanc - :source_amount, usdt = usdt + :destination_amount WHERE email = :email");
                } else if (destinationCoin == "eth") {
                    selectQuery.prepare("SELECT eth_balanc FROM wallets WHERE email = :email");
                    selectQuery.bindValue(":email", email);
                    if (selectQuery.exec() && selectQuery.next()) {
                        float currentETH = selectQuery.value(0).toFloat();
                        if (currentETH < sourceAmount) {
                            qDebug() << "Insufficient ETH balance";
                            socket->write("Insufficient ETH balance");
                            return;
                        }
                    }
                    updateQuery.prepare("UPDATE wallets SET eth_balanc = eth_balanc - :source_amount, usdt = usdt + :destination_amount WHERE email = :email");
                } else if (destinationCoin == "trx") {
                    selectQuery.prepare("SELECT trx_balanc FROM wallets WHERE email = :email");
                    selectQuery.bindValue(":email", email);
                    if (selectQuery.exec() && selectQuery.next()) {
                        float currentTRX = selectQuery.value(0).toFloat();
                        if (currentTRX < sourceAmount) {
                            qDebug() << "Insufficient TRX balance";
                            socket->write("Insufficient TRX balance");
                            return;
                        }
                    }
                    updateQuery.prepare("UPDATE wallets SET trx_balanc = trx_balanc - :source_amount, usdt = usdt + :destination_amount WHERE email = :email");
                }
                updateQuery.bindValue(":destination_amount", destinationAmount);
                updateQuery.bindValue(":source_amount", sourceAmount);
                updateQuery.bindValue(":email", email);

                if (!updateQuery.exec()) {
                    qDebug() << "Coin wasn't sold: " << updateQuery.lastError().text();
                    socket->write("Error");
                } else {
                    qDebug() << "Coin was sold";
                    socket->write("Success");
                }
            }
            else if (transactionType == "increase") {
                updateQuery.prepare("UPDATE wallets SET usdt = usdt + :destination_amount WHERE email = :email");
                updateQuery.bindValue(":destination_amount", destinationAmount);
                updateQuery.bindValue(":email", email);

                if (!updateQuery.exec()) {
                    qDebug() << "The increase was not successful: " << updateQuery.lastError().text();
                    socket->write("Error");
                } else {
                    qDebug() << "The increase was successful";
                    socket->write("Success");
                }
            }
            else if (transactionType == "decrease") {
                selectQuery.prepare("SELECT usdt FROM wallets WHERE email = :email");
                selectQuery.bindValue(":email", email);
                if (selectQuery.exec() && selectQuery.next()) {
                    float currentUSDT = selectQuery.value(0).toFloat();
                    if (currentUSDT < sourceAmount) {
                        qDebug() << "Insufficient USDT balance";
                        socket->write("Insufficient USDT balance");
                        return;
                    }
                }
                updateQuery.prepare("UPDATE wallets SET usdt = usdt - :source_amount WHERE email = :email");
                updateQuery.bindValue(":source_amount", sourceAmount);
                updateQuery.bindValue(":email", email);
                if (!updateQuery.exec()) {
                    qDebug() << "The withdrawal was not successful: " << updateQuery.lastError().text();
                    socket->write("Error");
                } else {
                    qDebug() << "The withdrawal was successful";
                    socket->write("Success");
                }
            }
            else if (transactionType == "trans") {}
        } else {
            qDebug() << "Can't open wallets Database: " << query.lastError().text();
        }
    }
    else {
        qDebug() << "Unknown request type";
        socket->write("Unknown request type");
    }

    socket->flush();
    socket->close();
}

    // QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    // if (!socket) return;

    // QByteArray data = socket->readAll();
    // QJsonDocument doc = QJsonDocument::fromJson(data);
    // QJsonObject json = doc.object();

    // QString email = json["email"].toString();
    // QString password = json["password"].toString();
    // QString name = json["name"].toString();
    // QString address = json["address"].toString();
    // QString phoneNumber = json["phoneNumber"].toString();

    // QSqlQuery query;
    // query.prepare("INSERT INTO users (email, password, name, address, phoneNumber) "
    //               "VALUES (?, ?, ?, ?, ?, ?)");
    // query.addBindValue(email);
    // query.addBindValue(password);
    // query.addBindValue(name);
    // query.addBindValue(address);
    // query.addBindValue(phoneNumber);

    // if (!query.exec()) {
    //     qDebug() << "Insert error:" << query.lastError().text();
    //     socket->write("Error");
    // } else {
    //     qDebug() << "Insert success";
    //     socket->write("Success");
    // }

    // socket->flush();
    // socket->close();
// }
// void MyTcpServer::processJsonData(const QJsonObject &json) {
//     QString email = json["email"].toString();
//     QString password = json["password"].toString();
//     QString name = json["name"].toString();
//     QString address = json["address"].toString();
//     QString phoneNumber = json["phoneNumber"].toString();

//     QSqlQuery query;
//     query.prepare("INSERT INTO users (email, password, name, address, phoneNumber) "
//                   "VALUES (?, ?, ?, ?, ?, ?)");
//     query.addBindValue(email);
//     query.addBindValue(password);
//     query.addBindValue(name);
//     query.addBindValue(address);
//     query.addBindValue(phoneNumber);

//     if (!query.exec()) {
//         qDebug() << "Insert error:" << query.lastError().text();
//         socket->write("Error");
//     } else {
//         qDebug() << "Insert success";
//         socket->write("Success");
//     }
// }
