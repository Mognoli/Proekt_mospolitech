#include "mytcpthread.h"
#include "functionsforserver.h"

MyTcpThread::MyTcpThread(qintptr threadDesc, QObject *parent) : QThread{parent} {
    this->socketDescriptor = threadDesc;
}

void MyTcpThread::run() {
    socket = new QTcpSocket();
    socket->setSocketDescriptor(this->socketDescriptor);


    //Qt::DirectConnection used to emit readyRead slot immidiately on signal call
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << "Client connected, descriptor: " << this->socketDescriptor;

    exec();
}

// to fix: readAll() works incorrectly with PuTTY telnet client
void MyTcpThread::readyRead() {
    if (socket->bytesAvailable()>0) {
        QByteArray command = socket->readAll();
        if (command.length() > 0) socket->write(parsing(command, socket->socketDescriptor()));
    }

//    QString array="";
//    array=socket->readAll();
//    QByteArray mas=array.toLocal8Bit();
//    socket->write(parsing(mas, socket->socketDescriptor()));
}

void MyTcpThread::disconnected() {
    qDebug() << "Client disconnected, descriptor: " << this->socketDescriptor;

    // place socket deletion in queue, exit thread
    socket->deleteLater();
    exit(0);
    // remove socketDescriptor from "logged in users" table in database (?)
}
