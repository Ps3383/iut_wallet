#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QDialog>

namespace Ui {
class signinpage;
}

class signinpage : public QDialog
{
    Q_OBJECT

public:
    explicit signinpage(QWidget *parent = nullptr);
    ~signinpage();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::signinpage *ui;
};

#endif // SIGNINPAGE_H
