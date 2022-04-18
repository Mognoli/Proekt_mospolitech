/*!
 * \file
 */

#include <QCoreApplication>
#include "mytcpserver.h"
#include "DataBase.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer mainServer;
    return a.exec();
}

DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;
