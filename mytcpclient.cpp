#include "mytcpclient.h"
#include <QDebug>

MyTcpClient::MyTcpClient(QObject *parent)
    : QObject{parent}
{
}

void MyTcpClient::setSocket(quint16 descriptor) {
    mTcpSocket = new QTcpSocket(this);

    connect(mTcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(mTcpSocket, SIGNAL(readyRead()), this, SLOT(slotServerRead()));
    connect(mTcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    mTcpSocket->setSocketDescriptor(descriptor);

    qDebug() << "A new client connected, descriptor: " << mTcpSocket->socketDescriptor();
}


//эта функция получает в качестве аргумента результат emit echo(echoString), полученный по завершению thread echoTask
void MyTcpClient::taskResult(QString echoString) {
    QByteArray responce = echoString.toUtf8();
    mTcpSocket->write(responce);
}


void MyTcpClient::connected() {
    qDebug() << "Client connected (slot debug called)";
}

void MyTcpClient::slotServerRead() {
    qDebug() << "readyRead";
    Task *echoTask = new Task();

    // QThreadPool будет удалять процесс после вызова run
    echoTask->setAutoDelete(true);
    connect(echoTask, SIGNAL(echo(QString)), this, SLOT(taskResult(QString echoString)), Qt::QueuedConnection); // Qt:DirectConnection - Each thread created by Qt (including main thread and new threads created by QThread) have Event loop, the event loop is responsible for receiving signals and call aproporiate slots in its thread. Generaly executing a blocking operation inside an slot is bad practice, because it blocks the event loop of that threads so no other slots would be called. If you block an event loop (by making very time consuming or blocking operation) you will not receive events on that thread until the event loop will be unblocked.

    // запускает echoTask->run()
    QThreadPool::globalInstance()->start(echoTask);
}

void MyTcpClient::disconnected() {
    qDebug() << "Client disconnected (slot debug called)";
}
