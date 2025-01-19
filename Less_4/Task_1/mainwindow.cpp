#include "mainwindow.h"
#include "./ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    about = new QMessageBox();

    ui->pushButton->setCheckable(true);
    ui->progressBar->setValue(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);

    setStyleSheet(""); // Цвет по умолчанию
    ui->lightTheme->setChecked(true); //По умолчанию светлая тема

    // Подключение сигналов к слотам
    connect(ui->darkTheme, &QRadioButton::toggled, this, &MainWindow::changeColor);
    connect(ui->lightTheme, &QRadioButton::toggled, this, &MainWindow::changeColor);
    connect(ui->add10, &QAction::triggered, this, &MainWindow::add10);
    connect(ui->del10, &QAction::triggered, this, &MainWindow::del10);
    connect(ui->closeBut, &QAction::triggered, this, &MainWindow::closeBut);
    connect(ui->clearBut, &QAction::triggered, this, &MainWindow::clearBut);
    connect(ui->aboutProg, &QAction::triggered, this, &MainWindow::aboutProg);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::add10() {

    if (ui->progressBar->value() != 10) {
        ui->progressBar->setValue(++val);
    } else {
        ui->progressBar->setValue(0);
        val = 0;
    }
}

void MainWindow::del10() {

    if (ui->progressBar->value() != 0) {
        ui->progressBar->setValue(--val);
    } else {
        ui->progressBar->setValue(0);
        val = 0;
    }
}

void MainWindow::clearBut() {
    ui->progressBar->setValue(0);
    val = 0;
}

void MainWindow::closeBut() {
    QApplication::quit();
}

void MainWindow::aboutProg() {
    if (ui->darkTheme->isChecked()) {
        about->setStyleSheet("background-color: #241f31;"
                             "color: #ffffff;");
    } else {
        about->setStyleSheet("");
    }
    about->setWindowTitle("О программе");
    about->setText("Данная программа разработана для тестирования прогресс бара");
    about->show();
}

void MainWindow::on_add10_triggered() {
    void add10();
}

void MainWindow::on_del10_triggered() {
    void del10();
}

void MainWindow::on_clearBut_triggered() {
    void clearBut();
}

void MainWindow::on_closeBut_triggered() {
    void closeBut();
}

void MainWindow::on_aboutProg_triggered() {
    void aboutProg();
}

void MainWindow::changeColor() {
    // Проверяем, какая радиокнопка выбрана и меняем цвет
    if (ui->darkTheme->isChecked()) {

        this->setStyleSheet(
                "QWidget {"
                "   background-color: #241f31;" // Цвет окна
                "   color: #ffffff;" // Цвет текста окна
                "}"
                "QPushButton {"
                "   background-color: #33d17a;" // Цвет кнопок
                "   color: black;" // Цвет текста кнопок (можно изменить, если требуется)
                "}"
                "QProgressBar {"
                "   background-color: white;" // Цвет фона прогресс-бара
                "   color: black;" // Цвет текста прогресс-бара
                "   text-align: center;" // Текст по центру
                "}"
                "QProgressBar::chunk {"
                "   background-color: #33d17a;" // Цвет заполненной части прогресс-бара
                "}"
        );

    } else if (ui->lightTheme->isChecked()) {
        setStyleSheet(""); // Цвет по умолчанию
    }
}


void MainWindow::on_pushButton_toggled(bool checked) {
    if (checked) {
        if (ui->progressBar->value() != 10) {
            ui->progressBar->setValue(++val);
        } else {
            ui->progressBar->setValue(0);
            val = 0;
        }
    }

}

