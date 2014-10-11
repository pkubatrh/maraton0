#include "pojisteniclanek.h"
#include "ui_pojisteniclanek.h"
#include <QWebView>
#include <QNetworkProxyFactory>

Pojisteniclanek::Pojisteniclanek(QWidget *parent) {

}

Pojisteniclanek::Pojisteniclanek(const QString &str, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pojisteniclanek)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/images/per_tex.png")))));
    setPalette(*palette);
    QNetworkProxyFactory::setUseSystemConfiguration (true);
    //QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    ui->webView->load(QUrl(str));
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

void Pojisteniclanek::closeMe() {
    this->close();
    emit closing();
}


Pojisteniclanek::~Pojisteniclanek()
{
    delete ui;
}
