#ifndef JEZIBABA_H
#define JEZIBABA_H

#include <QMainWindow>

namespace Ui {
class jezibaba;
}

class jezibaba : public QMainWindow
{
    Q_OBJECT

public:
    explicit jezibaba(QWidget *parent = 0);
    ~jezibaba();

private:
    Ui::jezibaba *ui;
};

#endif // JEZIBABA_H
