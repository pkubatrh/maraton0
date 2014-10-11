#include "jezibaba.h"
#include "ui_jezibaba.h"
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QPainter>

jezibaba::jezibaba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jezibaba)
{
    this->days = 0;
    ui->setupUi(this);
    ui->label->resize(210,300);
    this->image = new QImage(":/images/kal.png");
    p = new QPainter(image);
    QFont f( "Arial", 150, QFont::Bold);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    ui->label->setPixmap(QPixmap::fromImage(*image));
    ui->label->setAlignment(Qt::AlignCenter);
}

jezibaba::~jezibaba()
{
    delete ui;
}

void jezibaba::on_label_clicked()
{
    this->days++;
    QFont f( "Arial", 150, QFont::Bold);
    p->eraseRect(image->rect());
    delete p;
    image = new QImage(":/images/kal.png");
    p = new QPainter(this->image);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    ui->label->setPixmap(QPixmap::fromImage(*image));
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->repaint();
}
