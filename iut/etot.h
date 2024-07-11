#ifndef ETOT_H
#define ETOT_H

#include <QDialog>

namespace Ui {
class ETOT;
}

class ETOT : public QDialog
{
    Q_OBJECT

public:
    explicit ETOT(QWidget *parent = nullptr);
    ~ETOT();

private slots:
    void on_back_clicked();

    void on_ok_clicked();

private:
    Ui::ETOT *ui;
};

#endif // ETOT_H
