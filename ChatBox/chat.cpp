#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_lineEdit_returnPressed()
{
    ui->plainTextEdit->appendPlainText("Jezibaba>> " + ui->lineEdit->text());
    ui->lineEdit->clear();
}
