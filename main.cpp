#include "gethostinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetHostInfo w;
    w.show();

    return a.exec();
}
