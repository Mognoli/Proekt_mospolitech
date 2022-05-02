#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QTcpSocket>
#include <QDebug>
#include <QtNetwork>
#include <QErrorMessage>
#include <QString>
#include <QByteArray>

#include <QObject>

class ConnectToServer : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QString ResulForClient;
public:
    explicit ConnectToServer(QObject *parent = nullptr);
    QString toServer(QString toServerMesseng);
public slots:
    void readSocket();
    void disconnectedSocket();
signals:

};
#endif // CONNECTTOSERVER_H
