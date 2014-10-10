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
}
