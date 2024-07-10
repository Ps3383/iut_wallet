#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QString>
//************************************************** Copy the contents of functions and paste them in the appropriate place ******************************************************************

// buy option
void createJasonforBuy_type(){
    QString email = "mahdi"; // get from client
    QString buy_coin = "coinName"; // get from user(همون جایی که کاربر وارد میکنه یه کاری بکن که مشخص بشه چه کوینی رو انتخاب کرده)
    float coin_price,coin_amount;
    coin_price  = 3405.5; //get from api
    coin_amount = 3.5; //get from user
    QJsonObject json;
    json["type"] = "transactions";
    json["sellORbuy"] = "buy";
    json["email"] = email;
    json["source_coin"] = "usdt";
    json["destination_coin"] = buy_coin;
    json["source_address"] = "";
    json["destination_address"] = "";
    json["source_amount"] = coin_amount * coin_price; // with this formula
    json["destination_amount"] = coin_amount;
}

// sell option
void createJasonforSell_type(){
    QString email = "mahdi"; // get from client
    QString sell_coin = "coinName"; // get from user(همون جایی که کاربر وارد میکنه یه کاری بکن که مشخص بشه چه کوینی رو انتخاب کرده)
    float coin_price,coin_amount;
    coin_price  = 3405.5; //get from api
    coin_amount = 3.5; //get from user
    QJsonObject json;
    json["type"] = "transactions";
    json["sellORbuy"] = "sell";
    json["email"] = email;
    json["source_coin"] = sell_coin;
    json["destination_coin"] = "usdt";
    json["source_address"] = "";
    json["destination_address"] = "";
    json["source_amount"] = coin_amount ;
    json["destination_amount"] = coin_amount * coin_price; // with this formula
}

//increase usdt amount
void createJasonforIncreace_usdt(){
    QString email = "mahdi"; // get from client
    float coin_amount;
    coin_amount = 3.5; //get from user
    QJsonObject json;
    json["type"] = "transactions";
    json["sellORbuy"] = "increase";
    json["email"] = email;
    json["source_coin"] = "";
    json["destination_coin"] = "usdt";
    json["source_address"] = "";
    json["destination_address"] = "";
    json["source_amount"] = 0.0 ;
    json["destination_amount"] = coin_amount;
}

//decrease usdt amount
void createJasonforDecreace_usdt(){
    QString email = "mahdi"; // get from client
    float coin_amount;
    coin_amount = 3.5; //get from user
    QJsonObject json;
    json["type"] = "transactions";
    json["sellORbuy"] = "decrease";
    json["email"] = email;
    json["source_coin"] = "usdt";
    json["destination_coin"] = "";
    json["source_address"] = "";
    json["destination_address"] = "";
    json["source_amount"] = coin_amount ;
    json["destination_amount"] = 0.0;
}
