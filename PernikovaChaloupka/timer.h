#ifndef TIMER_H
#define TIMER_H

#include <QLCDNumber>
#include <QTimer>
#include <QColor>
#include <QMouseEvent>

class timer : public QLCDNumber
{
    Q_OBJECT

public:
    int time;
    timer(QWidget *parent = 0);
    void setTime(int t);
    QTimer *tmr;
    bool running = false;

signals:
    void clicked();

public slots:
    void mousePressEvent(QMouseEvent *event);
    void start();
    void incMin();
    void incSec();
    void decSec();
    void decMin();

private slots:
    void showTime();
};


#endif // TIMER_H
