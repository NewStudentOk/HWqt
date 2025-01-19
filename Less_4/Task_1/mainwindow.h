#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    QMessageBox *about;

private slots:

    void on_pushButton_toggled(bool checked);

    void changeColor();

    void on_add10_triggered();

    void on_del10_triggered();

    void on_clearBut_triggered();

    void on_closeBut_triggered();

    void on_aboutProg_triggered();

    void add10();

    void del10();

    void clearBut();

    void closeBut();

    void aboutProg();

private:
    Ui::MainWindow *ui;
    int val = 0;
};

#endif // MAINWINDOW_H
