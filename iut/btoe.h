#ifndef BTOE_H
#define BTOE_H

#include <QDialog>

namespace Ui {
class BTOE;
}

class BTOE : public QDialog
{
    Q_OBJECT

public:
    explicit BTOE(QWidget *parent = nullptr);
    ~BTOE();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BTOE *ui;
};

#endif // BTOE_H
