#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QCamera>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    page.mainFrame()->load(QUrl("http://en.wikipedia.org/wiki/List_of_spells_in_Harry_Potter"));
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(readFirst()));
}

void MainWindow::readFirst() {
    QWebElement rootElem = page.mainFrame()->documentElement();
    qDebug() << rootElem.toPlainText();
    QWebElement headlines = rootElem.findFirst("h3");
    qDebug() << headlines.toPlainText();
    emit finished();
}

MainWindow::~MainWindow()
{
    delete ui;
}
