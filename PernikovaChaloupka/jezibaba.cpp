#include "jezibaba.h"
#include "ui_jezibaba.h"

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
