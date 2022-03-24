/*!
 * \file
 * \brief Заголовочный файл с описанием класса MyTcpServer
 */

#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include "mytcpthread.h"
//#include "DataBase.h"
#include <QObject>
#include <QTcpServer>
#include <QtNetwork>
#include <QDebug>
#include <QTcpSocket>

/*!
 * \brief MyTcpServer - класс, описывающий работу с сервером.
 * \details Класс MyTcpServer используется для инициализации TCP сервера, прослушивания и приема входящих подключений.
 */
class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    /*!
     * \brief MyTcpServer - конструктор класса MyTcpServer
     * \details Инициализирует сервер и устанавливает прослушивание входящих подключений с любого адреса к порту 33333
     * \param [in] parent - родительский объект QObject
     */
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
protected:
    /*!
     * \brief incomingConnection - переопределенная виртуальная функция класса QTcpServer
     * \details Вызывается при наличии входящего подключения. Инициализирует новый поток MyTcpThread и передает ему автоматически сгенерированный дескриптор для дальнейшего создания и работы с сокетом
     * \param [in] socketDescriptor - автоматически генерируемый дескриптор сокета
     */
    void incomingConnection(qintptr socketDescriptor);
//    QTcpSocket getSocketByDescriptor(qintptr desc);
private:
//    QMap<qintptr, QTcpSocket> *socketList;
};

#endif // MYTCPSERVER_H
