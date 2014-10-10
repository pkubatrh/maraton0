#ifndef CALENDAR_H
#define CALENDAR_H

#include <QLabel>

class calendar : public QLabel
{
    Q_OBJECT

public:
    int days;
    calendar();
    QLabel *label;
    QImage *image;
    QPainter *p;

public slots:
    void inc();
    void dec();
};

#endif // CALENDAR_H
