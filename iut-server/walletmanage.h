#ifndef WALLETMANAGE_H
#define WALLETMANAGE_H

#include <QDialog>

namespace Ui {
class wallet;
}

class wallet : public QDialog
{
    Q_OBJECT

public:
    explicit wallet(QWidget *parent = nullptr);
    ~wallet();
    void createWallet(const QString& email, const QString& walletName);
    void getBalance(const QString& email, const QString& walletName);
    void generateAddress(const QString& email, const QString& walletName);
    void getTransactionHistory(const QString& email, const QString& walletName);

signals:
    void walletCreated(const QString& response);
    void balanceFetched(const QJsonObject& response);
    void addressGenerated(const QJsonObject& response);
    void transactionHistoryFetched(const QJsonArray& response);

private:
    QString generateSeedPhrase();
    QString generateUniqueAddress();

    QSqlDatabase db;

private:
    Ui::walletmanage *ui;
};

#endif // WALLETMANAGE_H
