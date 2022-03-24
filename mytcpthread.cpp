/*!
 * \file
 * \brief Файл, содержащий имплементацию методов класса MyTcpThread
 */

#include "mytcpthread.h"
#include "functionsforserver.h"

MyTcpThread::~MyTcpThread() {
    requestInterruption();
    wait();
    if (DEBUG_ENV) qDebug() << "Thread instance terminated: client " << this->socketDescriptor;
}

MyTcpThread::MyTcpThread(qintptr threadDesc, QObject *parent) : QThread{parent} {
    this->socketDescriptor = threadDesc;
}

void MyTcpThread::run() {
    socket = new QTcpSocket();
    socket->setSocketDescriptor(this->socketDescriptor);


    //Qt::DirectConnection used to emit readyRead slot immidiately on signal call
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    if (DEBUG_ENV) qDebug() << "Client connected, descriptor: " << this->socketDescriptor;

    exec();
}

// to fix: readAll() works incorrectly with PuTTY telnet client
void MyTcpThread::readyRead() {
    if (socket->bytesAvailable()>0) {
        QByteArray command = socket->readAll();
        if (command.length() > 0) {
            socket->write(parsing(command, socket->socketDescriptor()));
            if (DEBUG_ENV) qDebug() << "Client " << socket->socketDescriptor() << " sent message: " << command;
        }
    }
}

void MyTcpThread::disconnected() {
    if (DEBUG_ENV) qDebug() << "Client disconnected, descriptor: " << this->socketDescriptor;

    socket->deleteLater();
    exit(0);
    // remove socketDescriptor from "logged in users" table in database (?)
}
