#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QTimer>
#include <QColor>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    int time;
    DigitalClock(QWidget *parent = 0);
    void setTime(int t);

private slots:
    void showTime();
    void start();
};

#endif // DIGITALCLOCK_H
