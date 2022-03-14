#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QtNetwork>
#include <QDebug>
#include <QTcpSocket>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor);
    //.
    QTcpSocket getSocketByDescriptor(qintptr desc);
private:
    //.
    QMap<qintptr, QTcpSocket> *socketList;
};

#endif // MYTCPSERVER_H
