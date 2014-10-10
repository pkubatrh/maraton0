#ifndef DETSKEOKENKO_H
#define DETSKEOKENKO_H

#include <QMainWindow>

namespace Ui {
class DetskeOkenko;
}

class DetskeOkenko : public QMainWindow
{
    Q_OBJECT

public:
    explicit DetskeOkenko(QWidget *parent = 0);
    ~DetskeOkenko();

public Q_SLOTS:
    void openVids();

private:
    Ui::DetskeOkenko *ui;

private Q_SLOTS:
    void closeMe();

Q_SIGNALS:
    void closing();
};

#endif // DETSKEOKENKO_H
