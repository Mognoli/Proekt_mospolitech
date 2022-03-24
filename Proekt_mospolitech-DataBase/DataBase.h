#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include <QString>
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * p_instance;
    public:
        ~DataBaseDestroyer() { delete p_instance;}
        void initialize(DataBase * p)
        {
            p_instance = p;
        }
};


class DataBase
{
    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;

        static QSqlDatabase db;
    protected:
        DataBase(){}
        DataBase(const DataBase& ) = delete;
        DataBase& operator = (DataBase &) = delete;
        ~DataBase() {
            db.close(); // Закрыть БД
        }
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                // создать и открыть БД
                p_instance = new DataBase();
               /* db = QSqlDatabase::addDatabase("QSQLITE");
                db.setDatabaseName("DataBaseForServer.db");

                if (!db.open())
                    qDebug() << db.lastError().text();
                    */

                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

// Создает таблицу
        /*static QString StartDataBase(){
            QSqlQuery query(p_instance->db);
            query.exec("CREATE TABLE User("
                       "login VARCHAR(20) NOT NULL, "
                       "password VARCHAR(20) NOT NULL"
                       "email VARCHAR(20) NOT NULL, "
                       ")");
            return "";
        };
*/
                /*
        static QString AddLogAndPas(QString login, QString password, QString email) {
            QSqlQuery query(db);
            query.prepare("INSERT INTO User(login, password, email)"
                              "VALUES (:login, :password, :email)");
            return "True";
        };


        static QString TestLogAndPas(QString login, QString password) {
            QSqlQuery query(p_instance->db);
            query.exec("SELECT * FROM User WHERE login = :login ");
            QSqlRecord rec = query.record();
            const int LoginIndex = rec.indexOf("login");
            const int PasswordIndex = rec.indexOf("password");
            query.next();
            qDebug()<<query.size();
            if (query.value(LoginIndex) == NULL) return "no such user";
                    else {
                QString TruePass = query.value(PasswordIndex).toString();
                if (TruePass != password) return "False";
                else return "true";
            }
        };*/
};


DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
//QSqlDatabase DataBase::db;

#endif // DATABASE_H
