#pragma once

#include <QMainWindow>
#include "login.h"
#include <ui/ui_login.h>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    login* logwin;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;

};



