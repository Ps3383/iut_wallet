#ifndef TTOE_H
#define TTOE_H

#include <QDialog>

namespace Ui {
class TTOE;
}

class TTOE : public QDialog
{
    Q_OBJECT

public:
    explicit TTOE(QWidget *parent = nullptr);
    ~TTOE();

private slots:
    void on_pushButton_clicked();

    void on_OK_clicked();

private:
    Ui::TTOE *ui;
};

#endif // TTOE_H
