#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = 0);
    ~Chat();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::Chat *ui;

Q_SIGNALS:
    void closing();
};

#endif // CHAT_H
