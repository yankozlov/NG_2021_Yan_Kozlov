#include "murmur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Murmur w;
    w.show();
    return a.exec();
}
