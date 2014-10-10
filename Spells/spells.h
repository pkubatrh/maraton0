#ifndef SPELLS_H
#define SPELLS_H

#include <QWidget>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>

namespace Ui {
class Spells;
}

class Spells : public QWidget
{
    Q_OBJECT

public:
    explicit Spells(QWidget *parent = 0);
    ~Spells();

private:
    Ui::Spells *ui;
    QWebPage page;

private Q_SLOTS:
    void readFirst();

};

#endif // SPELLS_H
