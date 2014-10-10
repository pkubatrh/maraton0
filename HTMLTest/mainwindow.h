#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebPage page;

private Q_SLOTS:
    void readFirst();

Q_SIGNALS:
    void finished();

};

#endif // MAINWINDOW_H
