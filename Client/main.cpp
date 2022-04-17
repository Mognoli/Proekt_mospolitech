#include "mainwindow.h"
#include "auth_reg.h"
#include "tasks.h"
#include "ConnectServer.h"
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnectServer::getInstance();
    MainWindow w;
    return a.exec();
}

ConnectServer * ConnectServer::p_instance = nullptr;
ConnectServerDestroyer ConnectServer::destroyer;
ConnectToServer * ConnectServer::Server = nullptr;
