#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

signals:
    void timeChanged(const QString &time);

public slots:
    void start();
    void stop();
    void reset();
    void lap();

private slots:
    void updateTime();

private:
    QTimer *timer;
    int elapsedMilliseconds;
};

#endif // STOPWATCH_H