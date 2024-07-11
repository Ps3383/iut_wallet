QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountpage.cpp \
    btoe.cpp \
    btot.cpp \
    buy.cpp \
    changeaddress.cpp \
    changename.cpp \
    changepass.cpp \
    changephone.cpp \
    createwallet.cpp \
    decrease.cpp \
    etob.cpp \
    etot.cpp \
    increase.cpp \
    main.cpp \
    mainwindow.cpp \
    sell.cpp \
    showwallet.cpp \
    sighuppage.cpp \
    signinpage.cpp \
    trade.cpp \
    ttob.cpp \
    ttoe.cpp \
    user.cpp

HEADERS += \
    accountpage.h \
    btoe.h \
    btot.h \
    buy.h \
    changeaddress.h \
    changename.h \
    changepass.h \
    changephone.h \
    createwallet.h \
    decrease.h \
    etob.h \
    etot.h \
    increase.h \
    mainwindow.h \
    sell.h \
    showwallet.h \
    sighuppage.h \
    signinpage.h \
    trade.h \
    ttob.h \
    ttoe.h \
    user.h

FORMS += \
    accountpage.ui \
    btoe.ui \
    btot.ui \
    buy.ui \
    changeaddress.ui \
    changename.ui \
    changepass.ui \
    changephone.ui \
    createwallet.ui \
    decrease.ui \
    etob.ui \
    etot.ui \
    increase.ui \
    mainwindow.ui \
    sell.ui \
    showwallet.ui \
    sighuppage.ui \
    signinpage.ui \
    trade.ui \
    ttob.ui \
    ttoe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    BTCETHTRX.qrc
