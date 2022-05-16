#ifndef FUNCTIONFORCLIENT_H
#define FUNCTIONFORCLIENT_H
#include "QString"
#include "QDebug"
#include "ConnectServer.h"

QString auth(QString login, QString password);
QString reg(QString login, QString password, QString email);

QString read_statistics(QString login);
QString check_answer(QString login, QString answer, QString condition, int task_number);
QString create_condition(int task_number);

#endif // FUNCTIONFORCLIENT_H
