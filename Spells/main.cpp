#include "spells.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Spells w;
    w.show();

    return a.exec();
}
