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
    Database.cpp \
    MyTcpServer.cpp \
    api.cpp \
    coins.cpp \
    main.cpp \
    mainwindow.cpp \
    wallet.cpp

HEADERS += \
    Database.h \
    HashArray.h \
    MyTcpServer.h \
    api.h \
    coins.h \
    mainwindow.h \
    wallet.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
