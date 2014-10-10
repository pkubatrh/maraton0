#include "ditevideo.h"
#include "ui_ditevideo.h"
#include <QWebView>
#include <QNetworkProxyFactory>

DiteVideo::DiteVideo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DiteVideo)
{
    ui->setupUi(this);
    QNetworkProxyFactory::setUseSystemConfiguration (true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    ui->webView->load(QUrl("https://www.youtube.com/embed/iGiJAn06AyQ"));
    ui->webView_2->load(QUrl("https://www.youtube.com/embed/p7qMG-L1oxU"));
    ui->webView_3->load(QUrl("https://www.youtube.com/embed/iPu-HVPCicE"));
    ui->webView_4->load(QUrl("https://www.youtube.com/embed/VLDKnWi2hNA"));
}

DiteVideo::~DiteVideo()
{
    delete ui;
}
