#include "functionforclient.h"

QString auth(QString login, QString password){
    QString result = "";
    result = "auth " + login + " " + password;
    return ConnectServer::ToServer(result);
}

QString reg(QString login, QString password, QString email){
    QString result = "";
    result = "reg " + login + " " + password + " " + email;
    return ConnectServer::ToServer(result);
}

QString read_statistics(QString login){
    QString MessengToServer = "ReadStatistics ";
    MessengToServer.append(login);
    return ConnectServer::ToServer(MessengToServer);
}

QString check_answer(QString login, QString answer, QString condition, int task_number){
    QString number = QString::number(task_number);
    QString MessengToServer = "TestAnswer " + login + " " + number + " " + condition + " " + answer;
    return ConnectServer::ToServer(MessengToServer);
}

QString create_condition(int task_number) {
    QString MessengToServer = "createCondition ";
    QString number = QString::number(task_number);
    MessengToServer.append(number);
    return ConnectServer::ToServer(MessengToServer);
}
