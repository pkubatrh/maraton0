#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent):QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(start()));
    timer->start(5000);

    setTime(300);

    resize(300,120);
}

void DigitalClock::setTime(int t)
{
    QString text;
    time = t;
    if(time / 60 < 10)
        text = "0";
    text.append(QString::number(time / 60, 10));
    text.append(":");
    if(time % 60 < 10)
        text.append("0");
    text.append(QString::number(time % 60, 10));

    display(text);
}

void DigitalClock::start()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();
}

void DigitalClock::showTime()
{
    if(time > 0)
        time--;
    else
        setPalette(QPalette(QPalette::WindowText,Qt::red));

    QString text;

    if(time / 60 < 10)
        text = "0";
    text.append(QString::number(time / 60, 10));
    text.append(":");
    if(time % 60 < 10)
        text.append("0");
    text.append(QString::number(time % 60, 10));
    if(time % 2 == 0 && time != 0)
        text[2] = ' ';

    display(text);
}
