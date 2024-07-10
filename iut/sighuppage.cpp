#include "sighuppage.h"
#include "ui_sighuppage.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include<QRegularExpression>


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
    QRegularExpression regex(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))");
    QRegularExpressionMatch match = regex.match(em);

    QRegularExpression regexx(R"((^\+?[0-9]{1,4}?[-.\s]?(\(?\d{1,3}?\)?[-.\s]?)?\d{1,4}[-.\s]?\d{1,4}[-.\s]?\d{1,9}$))");
    QRegularExpressionMatch matchh = regexx.match(tel);

 if (!match.hasMatch()) {
        QMessageBox::warning(this, "Sign Up Error", "Invalid email format");
  }
 else if((!matchh.hasMatch()) && tel.size()>=10){
     QMessageBox::warning(this, "Sign Up Error", "Invalid phonenumber format");
 }
 else{
    if (!em.isEmpty() && !ps.isEmpty()) {
        if(ps.size()>=4){
            User user1(em, ps, na, adr, tel);

            MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
            if (mainWindow) {
                mainWindow->sendUser(user1);
            }
            hide();
            MainWindow * b;
            b = new MainWindow(this);
            b->show();
        }
        else{
            QMessageBox::warning(this, "Sign up", "password atleast 4 character!");
        }
    }
    else {
        QMessageBox::warning(this, "Sign up", "Fill up email and password!");
    }
  }
}
