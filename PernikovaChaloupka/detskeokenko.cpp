#include "detskeokenko.h"
#include "ui_detskeokenko.h"

#include <QDebug>

DetskeOkenko::DetskeOkenko(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DetskeOkenko)
{
    ui->setupUi(this);
    ui->label->setText("Šikovná videa");
    ui->pushButton->setText("Zpět na výběr role");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(closeMe()));
}

void DetskeOkenko::closeMe() {
    emit closing();
    this->close();
}

DetskeOkenko::~DetskeOkenko()
{
    delete ui;
}
