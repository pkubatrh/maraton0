#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>

namespace Ui {
class Camera;
}

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private:
    Ui::Camera *ui;

Q_SIGNALS:
    void closing();

public Q_SLOTS:
    void closeMe();

};

#endif // CAMERA_H
