#include "functionforclient.h"

QString auth(QString login, QString password){
    QString result = "";
    result = "auth " + login + " " + password;
    qDebug() << result;
    return "true";
}

QString reg(QString login, QString password, QString email){
    QString result = "";
    result = "reg " + login + " " + password + " " + email;
    qDebug() << result;
    return "true";
}

QString check_answer(QString answer, QString input_for_task, int task_number){
    //отправлять на сервер и получаем
    return "true";
}
