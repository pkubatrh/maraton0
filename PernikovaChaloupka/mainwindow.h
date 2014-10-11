#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private Q_SLOTS:
    void debugPrint();

public Q_SLOTS:
    void detatko();
    void jezib();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
