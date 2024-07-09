#ifndef CHANGENAME_H
#define CHANGENAME_H

#include <QDialog>

namespace Ui {
class changename;
}

class changename : public QDialog
{
    Q_OBJECT

public:
    explicit changename(QWidget *parent = nullptr);
    ~changename();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::changename *ui;
};

#endif // CHANGENAME_H
