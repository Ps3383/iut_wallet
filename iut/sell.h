#ifndef SELL_H
#define SELL_H

#include <QDialog>

namespace Ui {
class sell;
}

class sell : public QDialog
{
    Q_OBJECT

public:
    explicit sell(QWidget *parent = nullptr);
    ~sell();

private slots:
    void on_back_clicked();

    void on_sell_2_clicked();

private:
    Ui::sell *ui;
};

#endif // SELL_H
