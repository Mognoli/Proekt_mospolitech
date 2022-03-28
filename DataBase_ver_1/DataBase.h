#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include <QString>
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
        }
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                // создать и открыть БД
                p_instance = new DataBase();
                p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
                p_instance->db.setDatabaseName("DataBaseForServer.db");

                if (!p_instance->db.open())
                    qDebug() << p_instance->db.lastError().text();


                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        static QString AddLogAndPas(QString login, QString password, QString email) {
            if (DataBase::TestLogAndPas(login, password) != "NoSuchUser") return "SuchUserAlreadyExists";
            else {
                QSqlQuery query(p_instance->db);
                query.prepare("INSERT INTO User(login, password, email)"
                                "VALUES (:login, :password, :email)");
                query.bindValue(":login", login);
                query.bindValue(":password", password);
                query.bindValue(":email", email);
                query.exec();
            return "True";
            }
        };

        static QString TestLogAndPas(QString login, QString password) {
            QSqlQuery query(p_instance->db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();
            int PasswordIndex = rec.indexOf("password");
            if (!query.next()) return "NoSuchUser";
            else {
                QString TruePassword = query.value(PasswordIndex).toString();
                if (TruePassword == password) return "True";
                else return "False";
            }
        }



        static void closeDB()
        {
            p_instance->db.close(); // Закрыть БД
        }

};


DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

#endif // DATABASE_H
