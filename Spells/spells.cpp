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
