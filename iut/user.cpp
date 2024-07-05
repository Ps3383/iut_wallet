#include "user.h"

User::User(const QString& email, const QString& password, const QString& name,
           const QString& address, const QString& phoneNumber):email(email),
    password(password), name(name),
    address(address), phoneNumber(phoneNumber) {}


