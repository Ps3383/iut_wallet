#ifndef CHANGEADDRESS_H
#define CHANGEADDRESS_H

#include <QDialog>

namespace Ui {
class changeaddress;
}

class changeaddress : public QDialog
{
    Q_OBJECT

public:
    explicit changeaddress(QWidget *parent = nullptr);
    ~changeaddress();

private slots:
    void on_backkk_clicked();

    void on_adddd_clicked();

private:
    Ui::changeaddress *ui;
};

#endif // CHANGEADDRESS_H
