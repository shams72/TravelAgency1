\

#include "holiday.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    holiday w;
    w.show();

    return a.exec();
}
