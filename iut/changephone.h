#ifndef CHANGEPHONE_H
#define CHANGEPHONE_H

#include <QDialog>

namespace Ui {
class changephone;
}

class changephone : public QDialog
{
    Q_OBJECT

public:
    explicit changephone(QWidget *parent = nullptr);
    ~changephone();

private slots:
    void on_backk_clicked();

    void on_addd_clicked();

private:
    Ui::changephone *ui;
};

#endif // CHANGEPHONE_H
