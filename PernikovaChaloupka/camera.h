#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>

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
    QCamera *camera;

Q_SIGNALS:
    void closing();

public Q_SLOTS:
    void closeMe();

};

#endif // CAMERA_H
