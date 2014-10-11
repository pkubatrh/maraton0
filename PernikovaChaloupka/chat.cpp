#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
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

Chat::~Chat()
{
    delete ui;
}

void Chat::on_lineEdit_returnPressed()
{
    ui->plainTextEdit->appendPlainText("Jezibaba>> " + ui->lineEdit->text());
    ui->lineEdit->clear();
}

void Chat::on_pushButton_clicked()
{
    emit closing();
    this->close();
}
