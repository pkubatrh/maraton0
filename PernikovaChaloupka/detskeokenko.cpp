#include "detskeokenko.h"
#include "ui_detskeokenko.h"
#include "ditevideo.h"
#include "camera.h"
#include "pojisteniclanek.h"

#include <QDebug>
#include <QPalette>
#include <QDesktopWidget>

DetskeOkenko::DetskeOkenko(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DetskeOkenko)
{
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/images/per_tex.png")))));
    setPalette(*palette);
    ui->setupUi(this);
    ui->gridLayout_2->setAlignment(Qt::AlignCenter);
    ui->label->setText("Šikovná videa");
    ui->label_2->setText("Poslední zpráva rodičům");
    ui->label_4->setText("Pojištění");
    ui->label_5->setText("Sebeobrana");
    ui->label_6->setText("Motlitby");
    QPixmap pixmap(":/images/arrow_green.png");
    QIcon ButtonIcon(pixmap);
    ui->pushButton->setIcon(ButtonIcon);
    QRect *r = new QRect();
    r->setWidth(200);
    r->setHeight(30);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton->setMaximumHeight(30);
    ui->pushButton->setMaximumWidth(200);
    ui->pushButton->setFlat(true);
    ui->pushButton->setIconSize(r->size());
    ui->pushButton->setText("");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(closeMe()));
    connect(ui->label, SIGNAL(clicked()), this, SLOT(openVids()));
    connect(ui->label_2, SIGNAL(clicked()), this, SLOT(openCam()));
    connect(ui->label_4, SIGNAL(clicked()), this, SLOT(openPoj()));
    connect(ui->label_5, SIGNAL(clicked()), this, SLOT(openSeb()));
    connect(ui->label_6, SIGNAL(clicked()), this, SLOT(openMot()));
    this->days = 0;
    ui->label_3->resize(210,300);
    this->image = new QImage(":/images/kal.png");
    p = new QPainter(image);
    QFont f( "Arial", 150, QFont::Bold);
    p->setFont(f);
    p->drawText(image->rect(), Qt::AlignCenter, QString::number(days, 10));
    ui->label_3->setPixmap(QPixmap::fromImage(*image));
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(QPixmap(":/images/yt_logo.png").scaled(QApplication::desktop()->screenGeometry().width()/4.6, QApplication::desktop()->screenGeometry().height()/6.0));
    ui->label_2->setPixmap(QPixmap(":/images/webka.png").scaled(QApplication::desktop()->screenGeometry().width()/4.6, QApplication::desktop()->screenGeometry().height()/3.2));
    ui->label_6->setPixmap(QPixmap(":/images/mot.gif").scaled(QApplication::desktop()->screenGeometry().width()/4.6, QApplication::desktop()->screenGeometry().height()/2.8));
    ui->label_4->setPixmap(QPixmap(":/images/money.jpg").scaled(QApplication::desktop()->screenGeometry().width()/4.4, QApplication::desktop()->screenGeometry().height()/3.2));
    ui->label_5->setPixmap(QPixmap(":/images/krav.png").scaled(QApplication::desktop()->screenGeometry().width()/4.2, QApplication::desktop()->screenGeometry().height()/3.2));

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
    QObject *v = QObject::sender();
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

void DetskeOkenko::openCam() {
    Camera *cam = new Camera();
    cam->showFullScreen();
    connect(cam, SIGNAL(closing()), this, SLOT(closeVids()));
}

void DetskeOkenko::openPoj() {
    Pojisteniclanek *poj = new Pojisteniclanek("https://www.kb.cz/cs/lide/obcane/detske-zivotni-pojisteni-broucek.shtml");
    poj->showFullScreen();
    connect(poj, SIGNAL(closing()), this, SLOT(closeVids()));
}

void DetskeOkenko::openSeb() {
    Pojisteniclanek *poj = new Pojisteniclanek("http://www.stream.cz/porady/skolapreziti");
    poj->showFullScreen();
    connect(poj, SIGNAL(closing()), this, SLOT(closeVids()));
}

void DetskeOkenko::openMot() {
    Pojisteniclanek *poj = new Pojisteniclanek("http://www.modlitba.cz/?pid=78&xid=_48");
    poj->showFullScreen();
    connect(poj, SIGNAL(closing()), this, SLOT(closeVids()));
}
