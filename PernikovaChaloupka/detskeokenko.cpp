#include "detskeokenko.h"
#include "ui_detskeokenko.h"
#include "ditevideo.h"

#include <QDebug>

DetskeOkenko::DetskeOkenko(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DetskeOkenko)
{
    this->setStyleSheet("background: #FFF");
    ui->setupUi(this);
    ui->label->setText("Šikovná videa");
    ui->pushButton->setText("Zpět na výběr role");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(closeMe()));
    connect(ui->label, SIGNAL(clicked()), this, SLOT(openVids()));
    this->days = 0;
    ui->label_3->resize(210,300);
    this->image = new QImage(":/images/kal.png");
    p = new QPainter(image);
    QFont f( "Arial", 150, QFont::Bold);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    ui->label_3->setPixmap(QPixmap::fromImage(*image));
    ui->label_3->setAlignment(Qt::AlignCenter);
}

void DetskeOkenko::closeMe() {
    emit closing();
    this->close();
}

DetskeOkenko::~DetskeOkenko()
{
    delete ui;
}

void DetskeOkenko::openVids()
{
    DiteVideo *v = new DiteVideo();
    v->showFullScreen();
    connect(v, SIGNAL(closing()), this, SLOT(closeVids()));
}

void DetskeOkenko::closeVids() {
    DiteVideo *v = qobject_cast<DiteVideo *>(QObject::sender());
    delete v;
    this->showFullScreen();
}

void DetskeOkenko::on_label_3_clicked()
{
    this->days++;
    QFont f( "Arial", 150, QFont::Bold);
    p->eraseRect(image->rect());
    delete p;
    image = new QImage(":/images/kal.png");
    p = new QPainter(this->image);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    ui->label_3->setPixmap(QPixmap::fromImage(*image));
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_3->repaint();
}
