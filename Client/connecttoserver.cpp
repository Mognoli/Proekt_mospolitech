#include "connecttoserver.h"

#include <QMessageBox>

ConnectToServer::ConnectToServer(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 33333);
    if (!socket->waitForConnected()) {
        QMessageBox::critical(NULL, QObject::tr(""), QObject::tr("Error connect to server"));
    }
    connect(socket,SIGNAL(readyRead()),this ,SLOT(readSocket()));
    connect(socket,SIGNAL(disconnected()),this ,SLOT(disconnectedSocket()));
}

QString ConnectToServer::toServer(QString toServerMesseng){
    ResulForClient = "ErrorRead";
    QByteArray ResultForServer;
    ResultForServer += toServerMesseng.toUtf8();
    socket->write(ResultForServer);
    socket->waitForReadyRead(100);
    return ResulForClient;
}

void ConnectToServer::readSocket(){
    QByteArray FromServer = socket->readAll();
    ResulForClient = QString(FromServer);
}

void ConnectToServer::disconnectedSocket(){
    QMessageBox::critical(NULL, QObject::tr(""), QObject::tr("Disconnected for server"));
}

