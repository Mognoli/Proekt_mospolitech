#include "mainwindow.h"
#include "auth_reg.h"
#include "tasks.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
