#include "mytcpserver.h"
#include "mytcpthread.h"

MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent){
    if (this->listen(QHostAddress::Any, 33333)) {qDebug() << "Server started on port 33333";}
    else {qDebug() << "Server not started, check for errors";}


}

// виртуальная функция класса QTcpServer
// вызывается при наличии входящего подключения, генерирует сокет и дескриптор
void MyTcpServer::incomingConnection(qintptr socketDescriptor) {
    MyTcpThread *newClient = new MyTcpThread(socketDescriptor, this);
    connect(newClient, SIGNAL(finished()), newClient, SLOT(deleteLater()));

    // вызов функции run() класса MyTcpThread объекта newClient
    newClient->start();
}
