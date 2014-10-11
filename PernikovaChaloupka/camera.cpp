#include "camera.h"
#include "ui_camera.h"
#include <QCamera>
#include <QCameraViewfinder>

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
    this->setWindowModality(Qt::WindowModal);
    QCamera* camera;

    QByteArray cameraDevice = QCamera::availableDevices()[0];
    camera = new QCamera(cameraDevice);

    camera->setViewfinder(ui->viewfinder);

    camera->setCaptureMode(QCamera::CaptureStillImage);

    //set the viewfinder to be the central widget of mainWindow
    //camera->setViewfinder(ui->viewfinder);
    camera->start();
}

Camera::~Camera()
{
    delete ui;
}
