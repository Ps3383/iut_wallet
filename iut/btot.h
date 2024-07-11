#ifndef BTOT_H
#define BTOT_H

#include <QDialog>

namespace Ui {
class BTOT;
}

class BTOT : public QDialog
{
    Q_OBJECT

public:
    explicit BTOT(QWidget *parent = nullptr);
    ~BTOT();

private slots:
    void on_pushButton_clicked();

    void on_ok_clicked();

private:
    Ui::BTOT *ui;
};

#endif // BTOT_H
