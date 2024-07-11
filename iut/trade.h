#ifndef TRADE_H
#define TRADE_H

#include <QDialog>

namespace Ui {
class trade;
}

class trade : public QDialog
{
    Q_OBJECT

public:
    explicit trade(QWidget *parent = nullptr);
    ~trade();

private slots:
    void on_back_clicked();



    void on_BtoE_clicked();

    void on_BtoT_clicked();

    void on_EtoB_clicked();

    void on_EtoT_clicked();

    void on_TtoB_clicked();

    void on_TtoE_clicked();

private:
    Ui::trade *ui;
};

#endif // TRADE_H
