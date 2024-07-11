#ifndef INCREASE_H
#define INCREASE_H

#include <QDialog>

namespace Ui {
class increase;
}

class increase : public QDialog
{
    Q_OBJECT

public:
    explicit increase(QWidget *parent = nullptr);
    ~increase();

private slots:
    void on_pushButton_clicked();

    void on_increase_2_clicked();

private:
    Ui::increase *ui;
};

#endif // INCREASE_H
