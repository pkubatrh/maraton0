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
}
