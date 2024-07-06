#include "sighuppage.h"
#include "ui_sighuppage.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

sighuppage::sighuppage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sighuppage)
{
    ui->setupUi(this);
}

sighuppage::~sighuppage()
{
    delete ui;
}

void sighuppage::on_pushButton_2_clicked()
{
    hide();
    MainWindow *b;
    b = new MainWindow(this);
    b->show();
}

void sighuppage::on_regi_clicked()
{
    QString em = ui->lineemail->text();
    QString ps = ui->linepassword->text();
    QString adr = ui->lineaddress->text();
    QString tel = ui->linetele->text();
    QString na = ui->linename->text();

    if (!em.isEmpty() && !ps.isEmpty()) {
        User user1(em, ps, na, adr, tel);
        QMessageBox::information(this, "Sign up", "Successfully added");

        // دسترسی به شیء MainWindow و فراخوانی sendUser
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
        if (mainWindow) {
            mainWindow->sendUser(user1);
        }

    }
    else {
        QMessageBox::warning(this, "Sign up", "Fill up email and password!");
    }
}
