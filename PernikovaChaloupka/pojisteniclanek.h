#ifndef POJISTENICLANEK_H
#define POJISTENICLANEK_H

#include <QMainWindow>

namespace Ui {
class Pojisteniclanek;
}

class Pojisteniclanek : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pojisteniclanek(QWidget *parent = 0);
    Pojisteniclanek(const QString& str, QWidget *parent = 0);
    ~Pojisteniclanek();

public Q_SLOTS:
    void closeMe();

Q_SIGNALS:
    void closing();

private:
    Ui::Pojisteniclanek *ui;
};

#endif // POJISTENICLANEK_H
