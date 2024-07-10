QT       += core gui
QT += sql
QT += core gui sql
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    API.cpp \
    Coins.cpp \
    Database.cpp \
    DatabaseManager.cpp \
    MyTcpServer.cpp \
    main.cpp \
    mainwindow.cpp \
    wallet.cpp

HEADERS += \
    ../../../../New folder/iut-server-wallet/API.h \
    ../../../../New folder/iut-server-wallet/API.h \
    API.h \
    Coins.h \
    Database.h \
    DatabaseManager.h \
    HashArray.h \
    MyTcpServer.h \
    mainwindow.h \
    wallet.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
