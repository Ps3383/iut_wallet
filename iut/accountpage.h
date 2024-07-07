#ifndef ACCOUNTPAGE_H
#define ACCOUNTPAGE_H

#include <QDialog>

namespace Ui {
class accountpage;
}

class accountpage : public QDialog
{
    Q_OBJECT

public:
    explicit accountpage(QWidget *parent = nullptr);
    ~accountpage();

private slots:
    void on_pushButton_2_clicked();

    void on_createwallet_clicked();

private:
    Ui::accountpage *ui;
};

#endif // ACCOUNTPAGE_H
