#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>

#include "task.h"

class MyTcpClient : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpClient(QObject *parent = nullptr);
    void setSocket(quint16 descriptor);

//signals:

public slots:
    void connected();
    // readyRead создает task для ...
    void slotServerRead();
    void disconnected();
    // слот - возвращает echoString клиенту (болььше информации в имплементации)
    void taskResult(QString echoString);

private:
    // сокет этого клиента
    QTcpSocket * mTcpSocket;
};

#endif // MYTCPCLIENT_H
