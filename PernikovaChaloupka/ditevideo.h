#ifndef DITEVIDEO_H
#define DITEVIDEO_H

#include <QMainWindow>

namespace Ui {
class DiteVideo;
}

class DiteVideo : public QMainWindow
{
    Q_OBJECT

public:
    explicit DiteVideo(QWidget *parent = 0);
    ~DiteVideo();

public Q_SLOTS:
    void closeMe();

Q_SIGNALS:
    void closing();

private:
    Ui::DiteVideo *ui;
};

#endif // DITEVIDEO_H
