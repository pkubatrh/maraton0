#include "jezibaba.h"
#include "chat.h"
#include "spells.h"
#include "pojisteniclanek.h"
#include "ui_jezibaba.h"
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QDesktopWidget>

jezibaba::jezibaba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jezibaba)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/images/witch_tex.png")))));
    setPalette(*palette);
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

    ui->label_2->setPixmap(QPixmap(":/images/spell_book.png").scaled(QApplication::desktop()->screenGeometry().width()/3.6, QApplication::desktop()->screenGeometry().height()/1.8));
    ui->label_3->setPixmap(QPixmap(":/images/cook_baby.jpg").scaled(QApplication::desktop()->screenGeometry().width()/4.0, QApplication::desktop()->screenGeometry().height()/1.8));

}

jezibaba::~jezibaba()
{
    delete ui;
}

void jezibaba::on_label_clicked()
{
    //qDebug() << "serepes\n";
    Chat *chat = new Chat();
    chat->showFullScreen();
    connect(chat, SIGNAL(closing()), this, SLOT(showFullScreen()));
}

void jezibaba::on_pushButton_clicked()
{
    emit closing();
    this->close();
}

void jezibaba::on_label_2_clicked()
{
    Spells *w = new Spells();
    w->showFullScreen();
    connect(w, SIGNAL(closing()), this, SLOT(showFullScreen()));
}

void jezibaba::on_widget_clicked()
{
    ui->widget->start();
}

void jezibaba::on_pushButton_2_clicked()
{
    if (!ui->widget->running)
        ui->widget->incMin();
}

void jezibaba::on_pushButton_5_clicked()
{
    if (!ui->widget->running)
        ui->widget->decMin();
}

void jezibaba::on_pushButton_3_clicked()
{
    if (!ui->widget->running)
        ui->widget->incSec();
}

void jezibaba::on_pushButton_4_clicked()
{
    if (!ui->widget->running)
        ui->widget->decSec();
}

void jezibaba::on_label_3_clicked()
{
    Pojisteniclanek *poj = new Pojisteniclanek("http://uncyclopedia.wikia.com/wiki/HowTo:Cook_Children");
    poj->showFullScreen();
    connect(poj, SIGNAL(closing()), this, SLOT(closeVids()));
}

void jezibaba::closeVids() {
    QObject *v = QObject::sender();
    delete v;
    this->showFullScreen();
}

void jezibaba::on_label_4_clicked()
{
    Pojisteniclanek *poj = new Pojisteniclanek("http://www.kornfeil.cz/");
    poj->showFullScreen();
    connect(poj, SIGNAL(closing()), this, SLOT(closeVids()));
}
