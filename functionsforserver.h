#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H

#include <QString>

QByteArray parsing(QString data_from_client, qintptr socketDescriptor);
QByteArray auth(QString login, QString password, qintptr socketDescriptor);
QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor);

#endif // FUNCTIONSFORSERVER_H
