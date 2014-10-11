#include "cookbook.h"
#include "ui_cookbook.h"

cookbook::cookbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cookbook)
{
    ui->setupUi(this);
}

cookbook::~cookbook()
{
    delete ui;
}
