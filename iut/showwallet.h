#ifndef SHOWWALLET_H
#define SHOWWALLET_H

#include <QDialog>

namespace Ui {
class showwallet;
}

class showwallet : public QDialog
{
    Q_OBJECT

public:
    explicit showwallet(QWidget *parent = nullptr);
    ~showwallet();

private slots:
    void on_pushButton_clicked();


    void on_shw_clicked();

private:
    Ui::showwallet *ui;
};

#endif // SHOWWALLET_H
