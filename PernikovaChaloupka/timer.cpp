#include "timer.h"

timer::timer(QWidget *parent):QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    //QTimer *timer = new QTimer(this);
    setTime(0);
    this->setStyleSheet("background: white");

    //resize(300,120);
}

void timer::setTime(int t)
{
    QString text;
    setPalette(QPalette());
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

void timer::incSec()
{
    time++;
    setTime(time);
}

void timer::incMin()
{
    time = time + 60;
    setTime(time);
}

void timer::decSec()
{
    //comment
    time--;
    if(time > 0)
        setTime(time);
    else
        setTime(0);
}

void timer::decMin()
{
    time = time - 60;
    if(time > 0)
        setTime(time);
    else
        setTime(0);
}

void timer::start()
{
    if (!running) {
        tmr = new QTimer(this);
        connect(tmr, SIGNAL(timeout()), this, SLOT(showTime()));
        tmr->start(1000);
        showTime();
        running = true;
    }
    else {
        tmr->stop();
        running = false;
    }
}

void timer::showTime()
{
    if(time > 0)
        time--;
    else {
        setPalette(QPalette(QPalette::WindowText,Qt::red));
        running = false;
        tmr->stop();
    }
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

void timer ::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        emit clicked();
    }
}
