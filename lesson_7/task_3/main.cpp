#include "spinboxer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpinBoxer w;
    w.show();
    return a.exec();
}
