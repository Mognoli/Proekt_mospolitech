/*!
 * \file
 * \brief Файл с имплементацией функций, заданных в functionsforserver.h
 */

#include "functionsforserver.h"
#include "DataBase.h"

QByteArray parsing (QString command, qintptr socketDescriptor) {
        QStringList parameters = command.split(QLatin1Char(' '));
        QString function = parameters.at(0);
        parameters.pop_front();

        if (function == "auth") {
            if (parameters.length() == 2) return auth(parameters.at(0), parameters.at(1), socketDescriptor);
            else return "Wrong parameters amount (Need 2). Check 'auth' documentation.\n";
        }
        else if (function == "reg") {
            if (parameters.length() == 3) return reg(parameters.at(0), parameters.at(1), parameters.at(2), socketDescriptor);
            else return "Wrong parameters amount (Need 3). Check 'reg' documentation.\n";
        }
        else return "Wrong syntax. Check for available commands.\n";
}


QByteArray auth(QString login, QString password, qintptr socketDescriptor)
{
    // auth emulation:

    // check for user in database; if exist:
    // push socketDescriptor in database in "logged in users" table (?)
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::TestLogAndPas(login, password).toUtf8());
    result.append("\n");
//    DataBase::closeDB();
    return result;
    // else return message "unable to log in"
}

QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor)
{
    // register emulation:

    // check for user in database; if not exist:
    // push parameters in "users" table; call "auth" func
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::AddLogAndPas(login, password, email).toUtf8());
    result.append("\n");
//    DataBase::closeDB();
    return result;
    // else return message "user already exist/not valid parameters"
}
