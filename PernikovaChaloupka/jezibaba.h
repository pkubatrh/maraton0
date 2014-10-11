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
    QPainter *p;

private slots:
    void on_label_clicked();

    void on_pushButton_clicked();

    void on_label_2_clicked();

private:
    Ui::jezibaba *ui;

Q_SIGNALS:
    void closing();
};

#endif // JEZIBABA_H
