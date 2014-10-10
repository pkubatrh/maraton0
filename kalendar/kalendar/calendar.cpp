#include "calendar.h"
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QPainter>

calendar::calendar()
{
    days = 0;
    label = new QLabel();
    label->resize(210,300);
    image = new QImage("/home/peta/maraton0/kalendar/kalendar/3.png");
    p = new QPainter(image);
    QFont f( "Arial", 150, QFont::Bold);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    label->setPixmap(QPixmap::fromImage(*image));
    label->setAlignment(Qt::AlignCenter);

    label->show();
}

void calendar::inc()
{
    days++;
    QFont f( "Arial", 150, QFont::Bold);
    image = new QImage("/home/peta/maraton0/kalendar/kalendar/3.png");
    p = new QPainter(image);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    label->setPixmap(QPixmap::fromImage(*image));
    label->setAlignment(Qt::AlignCenter);
    label->repaint();
}

void calendar::dec()
{
    days--;
    QFont f( "Arial", 150, QFont::Bold);
    image = new QImage("/home/peta/maraton0/kalendar/kalendar/3.png");
    p = new QPainter(image);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    label->setPixmap(QPixmap::fromImage(*image));
    label->setAlignment(Qt::AlignCenter);
    label->repaint();
}


