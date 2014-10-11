#include "camera.h"
#include "ui_camera.h"
#include <QCamera>
#include <QCameraViewfinder>

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/images/per_tex.png")))));
    setPalette(*palette);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
    ui->pushButton_3->setIcon(QIcon(QPixmap(":/images/arrow_green.png")));
    QRect *r = new QRect();
    r->setWidth(200);
    r->setHeight(30);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setMaximumHeight(30);
    ui->pushButton_3->setMaximumWidth(200);
    ui->pushButton_3->setFlat(true);
    ui->pushButton_3->setIconSize(r->size());
    ui->pushButton_3->setText("");
    this->setWindowModality(Qt::WindowModal);
    QCamera* camera;

    QByteArray cameraDevice = QCamera::availableDevices()[0];
    camera = new QCamera(cameraDevice);
    camera->setViewfinder(ui->viewfinder);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(closeMe()));
}

Camera::~Camera()
{
    delete ui;
}

void Camera::closeMe() {
    this->close();
    emit closing();
}
