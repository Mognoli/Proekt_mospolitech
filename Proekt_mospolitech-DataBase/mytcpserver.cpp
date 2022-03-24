/*!
 * \file
 * \brief Файл, содержащий имплементацию методов класса MyTcpServer
 */

#include "mytcpserver.h"

//

MyTcpServer::~MyTcpServer() {
    this->close();
}


MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent){
    if (this->listen(QHostAddress::Any, 33333)) {qDebug() << "Server started on port 33333";}
    else {qDebug() << "Server not started, check for errors";}

    DataBase::getInstance();
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor) {
    MyTcpThread *newClient = new MyTcpThread(socketDescriptor, this);
    connect(newClient, SIGNAL(finished()), newClient, SLOT(deleteLater()));

    newClient->start();
}
