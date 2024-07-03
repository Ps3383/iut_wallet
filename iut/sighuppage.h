#ifndef SIGHUPPAGE_H
#define SIGHUPPAGE_H

#include <QDialog>

namespace Ui {
class sighuppage;
}

class sighuppage : public QDialog
{
    Q_OBJECT

public:
    explicit sighuppage(QWidget *parent = nullptr);
    ~sighuppage();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::sighuppage *ui;
};

#endif // SIGHUPPAGE_H
