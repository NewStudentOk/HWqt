#include "stopwatch.h"

#include <QDateTime>

Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    elapsedMilliseconds = 0;
}

void Stopwatch::start()
{
    if (!timer->isActive()) {
        timer->start(100); // Обновление каждые 0.1 секунды
        emit timeChanged(QString("%1:%2.%3")
                                 .arg(elapsedMilliseconds / 60000, 2, 10, QChar('0'))
                                 .arg((elapsedMilliseconds % 60000) / 1000, 2, 10, QChar('0'))
                                 .arg(elapsedMilliseconds % 1000, 3, 10, QChar('0')));
    }
}

void Stopwatch::stop()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

void Stopwatch::reset()
{
    elapsedMilliseconds = 0;
    emit timeChanged("00:00.000");
}

void Stopwatch::updateTime()
{
    elapsedMilliseconds += 100; // Добавляем 0.1 секунды
    emit timeChanged(QString("%1:%2.%3")
                             .arg(elapsedMilliseconds / 60000, 2, 10, QChar('0'))
                             .arg((elapsedMilliseconds % 60000) / 1000, 2, 10, QChar('0'))
                             .arg(elapsedMilliseconds % 1000, 3, 10, QChar('0')));
}

void Stopwatch::lap()
{
    static int lapNumber = 1;
    int currentLapTime = elapsedMilliseconds;
    emit timeChanged(QString("Круг %1, время: %2 сек").arg(lapNumber++).arg(currentLapTime / 1000));
    elapsedMilliseconds = 0; // Сброс времени для следующего круга
}
