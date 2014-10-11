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

    void on_widget_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_label_3_clicked();
    void closeVids();

private:
    Ui::jezibaba *ui;

Q_SIGNALS:
    void closing();
};

#endif // JEZIBABA_H
