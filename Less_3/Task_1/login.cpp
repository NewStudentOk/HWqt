#include <QWidget>
#include <ui/ui_login.h>
#include "login.h"

login::login(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::login)
{
    ui->setupUi(this);
// для теста заполним поля, чтобы не вводить постоянно после отладки УДАЛИТЬ!
//    ui->lineEdit->setText("localhost");
//    ui->lineEdit_2->setText("test");
//    ui->spinBox->setValue(5432);
//    ui->lineEdit_3->setText("userdb2");
//    ui->lineEdit_4->setText("100");

    ui->lineEdit_4->setEchoMode(QLineEdit::Password); //скрытие вводимого текста
    mess = new QMessageBox();
}

login::~login()
{
    delete ui;
}

void login::on_connectDB_clicked()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(ui->lineEdit->text());
    db.setDatabaseName(ui->lineEdit_2->text());
    db.setPort(ui->spinBox->value());
    db.setUserName(ui->lineEdit_3->text());
    db.setPassword(ui->lineEdit_4->text());



    if(db.open())
    {
        close();
        mess->setText("Connected");
    }
    else
    {
        mess->setText("NOT Connected");
    }
    mess->show();
}

void login::on_closeButton_clicked()
{
    close();
}
