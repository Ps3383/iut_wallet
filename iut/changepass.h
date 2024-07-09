#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QDialog>

namespace Ui {
class changeinfo;
}

class changeinfo : public QDialog
{
    Q_OBJECT

public:
    explicit changeinfo(QWidget *parent = nullptr);
    ~changeinfo();

private slots:

    void on_pushButton_clicked();

    void on_changep_clicked();

private:
    Ui::changeinfo *ui;
};

#endif // CHANGEPASS_H
