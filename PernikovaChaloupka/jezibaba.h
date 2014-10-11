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
    int days;
    QImage *image;

private slots:
    void on_label_clicked();

private:
    Ui::jezibaba *ui;
};

#endif // JEZIBABA_H
