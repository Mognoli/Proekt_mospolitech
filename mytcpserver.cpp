#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QThread>

MyTcpServer::~MyTcpServer()
{
    this->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent){


    if(this->listen(QHostAddress::Any, 33333)){

        qDebug() << "server is started";
    } else {
//
        qDebug() << "server is not started";
//        connect(mainTcpServer, SIGNAL(newConnection()), this, SLOT(incomingConnection()));
    }
    qDebug() << this->isListening();
}

// каждое новое подключение вызывает эту функцию и инициирует новый thread; клиенту автоматически назначается дескриптор
void MyTcpServer::incomingConnection(qintptr socketDescriptor) {
    qDebug() << "Connection initialized\n";
    MyTcpClient *newClient = new MyTcpClient(this);
    newClient->setSocket(socketDescriptor);
//    qDebug() << "Connection initialized\n";
}






// deprecated
//void MyTcpServer::slotNewConnection(){

////    if (serverStatus==true) {
////        QTcpSocket *mTcpSocket = new QTcpSocket;
////        mTcpSocket = mainTcpServer->nextPendingConnection();
////        listTcpSocket->push_back(*mTcpSocket);
////        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
////        connect(mTcpSocket, &QTcpSocket::readChannelFinished, this, &MyTcpServer::slotServerRead);
////        connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
////    }
//}

//void MyTcpServer::slotServerRead(){
//    this->()->write(this->sender());
//    while(mTcpSocket->bytesAvailable()>0)
//    {
//        QByteArray array =mTcpSocket->readAll();
//        mTcpSocket->write(array);
//    }
//}

//void MyTcpServer::slotClientDisconnected(){
//    mTcpSocket->close();
//}
