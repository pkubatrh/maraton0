#include "spells.h"
#include "ui_spells.h"

Spells::Spells(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Spells)
{
    ui->setupUi(this);
    ui->listWidget->setStyleSheet("QListWidget::item, QListWidget::item:selected {color: black; border-bottom: 1px solid #A0A0A0 ;\
    background: lightgray; }; ");
    page.mainFrame()->load(QUrl("http://5.231.63.187/kouzla.html"));
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(readFirst()));
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

void Spells::readFirst() {
    QWebElement rootElem = page.mainFrame()->documentElement();
    //qDebug() << rootElem.toPlainText();
    QWebElementCollection headlines = rootElem.findAll("td");
    int i = 0;
    QString temp;
    while(i < headlines.count()) {
        temp=headlines.at(i).toPlainText() + "\n";
        i++;
        temp+=headlines.at(i).toPlainText();
        ui->listWidget->addItem(temp);
        i++;
    }
}


Spells::~Spells()
{
    delete ui;
}

void Spells::on_pushButton_clicked()
{
    emit closing();
    this->close();
}
