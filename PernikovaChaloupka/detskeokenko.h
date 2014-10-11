#ifndef DETSKEOKENKO_H
#define DETSKEOKENKO_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QPainter>

namespace Ui {
class DetskeOkenko;
}

class DetskeOkenko : public QMainWindow
{
    Q_OBJECT

public:
    explicit DetskeOkenko(QWidget *parent = 0);
    ~DetskeOkenko();
    int days;
    QImage *image;
    QPainter *p;

public Q_SLOTS:
    void openVids();
    void openCam();
    void openPoj();
    void openMot();
    void openSeb();

private:
    Ui::DetskeOkenko *ui;

private Q_SLOTS:
    void closeMe();
    void closeVids();

    void on_label_3_clicked();

Q_SIGNALS:
    void closing();
};

#endif // DETSKEOKENKO_H
