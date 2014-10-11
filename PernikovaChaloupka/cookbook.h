#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <QWidget>

namespace Ui {
class cookbook;
}

class cookbook : public QWidget
{
    Q_OBJECT

public:
    explicit cookbook(QWidget *parent = 0);
    ~cookbook();

private:
    Ui::cookbook *ui;
};

#endif // COOKBOOK_H
