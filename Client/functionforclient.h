#ifndef FUNCTIONFORCLIENT_H
#define FUNCTIONFORCLIENT_H
#include "QString"
#include "QDebug"
#include "ConnectServer.h"

QString auth(QString login, QString password);
QString reg(QString login, QString password, QString email);


QString check_answer(QString answer, QString input_for_task, int task_number);

#endif // FUNCTIONFORCLIENT_H
