#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chat.h"
#include "ui_chat.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "serepes\n";
    Chat *chat = new Chat();
    chat->show();
}
