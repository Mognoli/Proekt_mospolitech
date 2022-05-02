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

QString check_answer(QString answer, QString input_for_task, int task_number){
    //На сервере
    return "true";
}
