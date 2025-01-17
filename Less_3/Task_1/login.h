#pragma once

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {class login;}
QT_END_NAMESPACE

class login : public QWidget {
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    QMessageBox* mess;

private slots:
    void on_connectDB_clicked();
    void on_closeButton_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;

};

