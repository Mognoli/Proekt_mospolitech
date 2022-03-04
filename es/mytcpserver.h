#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <list>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    std::list <QTcpSocket*> mTcpSocket;
    //int cli=0;
    //int server_status;
};
#endif // MYTCPSERVER_H







