/*!
 * \file
 * \brief Файл с имплементацией функций, заданных в functionsforserver.h
 */

#include "functionsforserver.h"
#include "DataBase.h"
#include "createCondition.h"
#include "zadanieN1.h"

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
        else if (function == "ReadStatistics") {
            if (parameters.length() == 1) return ReadStatistics(parameters.at(0), socketDescriptor);
            else return "Wrong parameters \n";
        }
        else if (function == "TestAnswer") {
            if (parameters.length() == 7) return TestAnswer(parameters.at(0), parameters.at(1), parameters.at(2), parameters.at(3), parameters.at(4), parameters.at(5), parameters.at(6), socketDescriptor);
            else return "Wrong parameters \n";
        }
        else if (function == "createCondition") {
            if (parameters.length() == 1) return conditions(parameters.at(0), socketDescriptor);
            else return "Wrong parameters \n";
        }
        else return "Wrong syntax. Check for available commands.\n";

        // ReadStatistics ApdateStatistics
}


QByteArray auth(QString login, QString password, qintptr socketDescriptor)
{
    // auth emulation:

    // check for user in database; if exist:
    // push socketDescriptor in database in "logged in users" table (?)
    QByteArray result = "";
    result.append(DataBase::TestLogAndPas(login, password).toUtf8());
    return result;
    // else return message "unable to log in"
}

QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor)
{
    // register emulation:

    // check for user in database; if not exist:
    // push parameters in "users" table; call "auth" func
    QByteArray result = "";
    result.append(DataBase::AddLogAndPas(login, password, email).toUtf8());
    return result;
    // else return message "user already exist/not valid parameters"
}

QByteArray ReadStatistics(QString login, qintptr socketDescriptor)
{
    QByteArray result = "";
    result.append(DataBase::Read_statistic(login).toUtf8());
    return result;
}

QByteArray TestAnswer(QString login, QString numberQuestion, QString condition, QString answer1, QString answer2, QString answer3, QString answer4, qintptr socketDescriptor)
{
    QString answer = answer1 + " " + answer2 + " " + answer3 + " " + answer4;
    QByteArray result = "";
    QString trueAnswer = "";
    QString testResult = "";
    if (numberQuestion == "1") {
        trueAnswer = createAnswer(condition);
    }
    else if (numberQuestion == "2") {

    }
    else if (numberQuestion == "3") {

    }
    else if (numberQuestion == "4") {

    }
    if (trueAnswer == answer) testResult = "True";
    else testResult = "False";
    DataBase::Apdate_statistic(login, numberQuestion, testResult);
    result.append(testResult);
    return result;
}

QByteArray conditions(QString numbers, qintptr socketDescriptor) {
    QByteArray result = "";
    int number = numbers.toInt();
    result.append(createCondition(number));
    return result;
}
