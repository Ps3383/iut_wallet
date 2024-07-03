#ifndef USER_H
#define USER_H

#include <QMainWindow>


class User {
public:
    QString email;
    QString password;
    QString name;
    QString address;
    QString phoneNumber;

    // Constructor
    User(const QString& email, const QString& password, const QString& name,
         const QString& address, const QString& phoneNumber);
};

#endif // USER_H
