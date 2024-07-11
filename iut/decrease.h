#ifndef DECREASE_H
#define DECREASE_H

#include <QDialog>

namespace Ui {
class decrease;
}

class decrease : public QDialog
{
    Q_OBJECT

public:
    explicit decrease(QWidget *parent = nullptr);
    ~decrease();

private slots:
    void on_pushButton_clicked();

    void on_decreease_clicked();

private:
    Ui::decrease *ui;
};

#endif // DECREASE_H
