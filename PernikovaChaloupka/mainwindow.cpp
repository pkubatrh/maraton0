#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "detskeokenko.h"
#include "jezibaba.h"

#include <QDesktopWidget>
#include <QSound>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background: #FFF");
    ui->gridLayout->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(QPixmap(":/images/carodejka.jpg").scaled(QApplication::desktop()->screenGeometry().width()/2.2, QApplication::desktop()->screenGeometry().height()/1.3));
    ui->label2->setPixmap(QPixmap(":/images/dite.jpg").scaled(QApplication::desktop()->screenGeometry().width()/2.2, QApplication::desktop()->screenGeometry().height()/1.3));
    ui->label3->setText("<span style=\"font: 28pt; halign:center; font-weight: 600;\">Perníková chaloupka IS: Co jsi zač?</span>");
    ui->label3->setAlignment(Qt::AlignCenter);
    connect(ui->label, SIGNAL(clicked()), this, SLOT(debugPrint()));
    connect(ui->label, SIGNAL(clicked()), this, SLOT(jezib()));
    connect(ui->label2, SIGNAL(clicked()), this, SLOT(debugPrint()));
    connect(ui->label2, SIGNAL(clicked()), this, SLOT(detatko()));
}

void MainWindow::debugPrint() {
    qDebug() << "clicked a button";
}

void MainWindow::detatko() {
    QSound::play(":/sounds/lulu_cut.wav");
    DetskeOkenko *win = new DetskeOkenko();
    win->showFullScreen();
    connect(win, SIGNAL(closing()), this, SLOT(showFullScreen()));
}

void MainWindow::jezib() {
    QSound::play(":/sounds/Kratka_Helca.wav");
    jezibaba *win = new jezibaba();
    win->showFullScreen();
    connect(win, SIGNAL(closing()), this, SLOT(showFullScreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
