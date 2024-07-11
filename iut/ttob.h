#ifndef TTOB_H
#define TTOB_H

#include <QDialog>

namespace Ui {
class TTOB;
}

class TTOB : public QDialog
{
    Q_OBJECT

public:
    explicit TTOB(QWidget *parent = nullptr);
    ~TTOB();

private slots:
    void on_pushButton_clicked();

    void on_ok_clicked();

private:
    Ui::TTOB *ui;
};

#endif // TTOB_H
