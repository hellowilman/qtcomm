
#include <QApplication>


#include "test_comm.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    test_comm test;

    return a.exec();
}
