#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QAbstractSocket>
#include "mytcpclient.h"

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
    void incomingConnection(qintptr socketDescriptor);
public slots:
//    void slotNewConnection();
//    void slotClientDisconnected();
//    void slotServerRead();
//protected:

//private:
//    QTcpServer * mainTcpServer;
//    QList<QTcpSocket> * listTcpSocket;
//    bool serverStatus;
};
#endif // MYTCPSERVER_H

