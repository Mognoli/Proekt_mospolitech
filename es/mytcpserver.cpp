#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
    //cli++;
    QTcpSocket *ts;
        ts = mTcpServer->nextPendingConnection();
        mTcpSocket.push_back(ts);
        ts->write("Hello, World!!! I am echo server!\r\n");
        connect(ts, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(ts,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* ts = (QTcpSocket*)sender();
    QString array="";
    array=ts->readAll();
    QByteArray mas=array.toLocal8Bit();
    ts->write(mas);

}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* ts = (QTcpSocket*)sender();
    mTcpSocket.remove(ts);
    ts->close();
}
