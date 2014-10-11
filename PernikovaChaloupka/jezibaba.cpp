#include "jezibaba.h"
#include "chat.h"
#include "spells.h"
#include "ui_jezibaba.h"
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QPainter>

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
