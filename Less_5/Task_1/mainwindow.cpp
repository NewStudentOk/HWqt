#include "mainwindow.h"
#include "./ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stopwatch = new Stopwatch(this);

    connect(stopwatch, &Stopwatch::timeChanged, this, &MainWindow::updateTimeDisplay);
//    connect(stopwatch, SIGNAL(timeChanged(QString)), this, SLOT(updateTimeDisplay(QString)));


    ui->lapButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked()
{
    if (ui->startStopButton->text() == "Старт") {
        ui->startStopButton->setText("Стоп");
        ui->lapButton->setEnabled(true);
        stopwatch->start();
    } else {
        ui->startStopButton->setText("Старт");
        ui->lapButton->setEnabled(false);
        stopwatch->stop();
    }
}

void MainWindow::on_clearButton_clicked()
{
//    stopwatch->stop(); // Останавливаем секундомер
    stopwatch->reset(); // Сбрасываем время
//    ui->startStopButton->setText("Старт"); // Меняем текст кнопки на "Старт"
//    ui->lapButton->setEnabled(false); // Отключаем кнопку "Круг"
    ui->lapsBrowser->clear(); // Очищаем текстовый браузер
}

void MainWindow::on_lapButton_clicked()
{
    stopwatch->lap();
}

void MainWindow::updateTimeDisplay(const QString &time)
{
    if (time.contains("Круг")) { // Если это запись о круге
        ui->lapsBrowser->append(time);
    } else { // Иначе это текущее время секундомера
        ui->timeLabel->setText(time);
    }
}