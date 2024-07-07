#ifndef CREATEWALLET_H
#define CREATEWALLET_H

#include <QDialog>

namespace Ui {
class createwallet;
}

class createwallet : public QDialog
{
    Q_OBJECT

public:
    explicit createwallet(QWidget *parent = nullptr);
    ~createwallet();

private slots:
    void on_pushButton_2_clicked();

    void on_create_clicked();

private:
    Ui::createwallet *ui;
};

#endif // CREATEWALLET_H
