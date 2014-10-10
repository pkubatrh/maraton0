#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c = new calendar();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), c, SLOT(inc()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
