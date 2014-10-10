#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(QPixmap(":/images/carodejka.jpg").scaled(QApplication::desktop()->screenGeometry().width()/2.2, QApplication::desktop()->screenGeometry().height()/1.2));
    ui->label2->setPixmap(QPixmap(":/images/dite.jpg").scaled(QApplication::desktop()->screenGeometry().width()/2.2, QApplication::desktop()->screenGeometry().height()/1.2));
}

MainWindow::~MainWindow()
{
    delete ui;
}
