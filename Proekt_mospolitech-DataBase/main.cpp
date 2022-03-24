/*!
 * \file
 */

#include <QCoreApplication>
#include "mytcpserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //DataBase::StartDataBase(); // 1

    MyTcpServer mainServer;
    return a.exec();
}
