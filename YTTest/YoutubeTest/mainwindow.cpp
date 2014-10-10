#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QNetworkProxyFactory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QNetworkProxyFactory::setUseSystemConfiguration (true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    ui->webView->load(QUrl("https://www.youtube.com/embed/videoseries?list=FLt1N4Ci1b8Po-PuPtE2FfXQ"));

}


MainWindow::~MainWindow()
{
    delete ui;
}
