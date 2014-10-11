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
    ui->webView->load(QUrl("https://www.youtube.com/embed/4NJ2IhiOlyc"));
    ui->webView_2->load(QUrl("https://www.youtube.com/embed/p7qMG-L1oxU"));
    ui->webView_3->load(QUrl("https://www.youtube.com/embed/iPu-HVPCicE"));
    ui->webView_4->load(QUrl("https://www.youtube.com/embed/VLDKnWi2hNA"));
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
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(closeMe()));
}

void DiteVideo::closeMe() {
    this->close();
    //ui->webView->stop();
    //ui->webView_2->stop();
    //ui->webView_3->stop();
    //ui->webView_4->stop();
    emit closing();
}

DiteVideo::~DiteVideo()
{
    delete ui;
}
