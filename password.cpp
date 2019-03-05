#include "password.h"
#include "ui_password.h"
#include "QMessageBox"

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);
    ui->User_name->setFocus();
    this->setWindowTitle("Password");
}

Password::~Password()
{
    delete ui;
}

void Password::on_Confirm_clicked()
{
    if((ui->Password_QLine->text() == "void9948312527") && (ui->User_name->text() == "Administrator"))
    {
        emit QDialog::accept();
    }
    else
    {
        emit QDialog::reject();
        QMessageBox::warning(this,tr("温馨提醒"),tr("用户名或密码错误!"));
    }
}

void Password::on_Cancel_clicked()
{
    emit QDialog::reject();
}

void Password::Clear_Password()
{
    ui->User_name->setText(tr("Admin"));
    ui->Password_QLine->clear();
}
