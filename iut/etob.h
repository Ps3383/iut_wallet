#ifndef ETOB_H
#define ETOB_H

#include <QDialog>

namespace Ui {
class ETOB;
}

class ETOB : public QDialog
{
    Q_OBJECT

public:
    explicit ETOB(QWidget *parent = nullptr);
    ~ETOB();

private slots:
    void on_pushButton_clicked();

    void on_ok_clicked();

private:
    Ui::ETOB *ui;
};

#endif // ETOB_H
