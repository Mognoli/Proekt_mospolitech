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

        static void Apdate_statistic(QString login, QString answer, QString True_or_False) {
            QSqlQuery query(p_instance->db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            if (!query.next()) {qDebug() << "Error, no such user was found when adding to the database."; }
            else {
                QSqlRecord rec = query.record();
                int UserIndex = rec.indexOf("id");
                QString User_id = query.value(UserIndex).toString();
                QString name_column = 'n' + answer + "_all";
                QString request = "UPDATE Statistics set ";
                request.append(name_column);
                request.append(" = (");
                request.append(name_column);
                request.append(" + 1) WHERE User_id = ");
                request.append(User_id);
                query.prepare(request);
                query.exec();

                if (True_or_False == "True") {
                    QString name_column = 'n' + answer + "_true";
                    QString request = "UPDATE Statistics set ";
                    request.append(name_column);
                    request.append(" = (");
                    request.append(name_column);
                    request.append(" + 1) WHERE User_id = ");
                    request.append(User_id);
                    query.prepare(request);
                    query.exec();
                }
            }
        }

        static QString Read_statistic(QString login){
            QString result = login;
            result.append(" ");
            QSqlQuery query(p_instance->db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            if (!query.next()) {qDebug() << "Error! "; }
            else {
                QSqlRecord rec = query.record();
                int UserIndex = rec.indexOf("id");
                QString User_id = query.value(UserIndex).toString();
                QString zapros = "SELECT * FROM Statistics WHERE User_id = ";
                zapros.append(User_id);
                query.prepare(zapros);
                query.exec();
                if (!query.next()) {qDebug() << "Error! "; }
                else {
                    for (int i = 1; i<=4; i++) {
                        QString request = "n";
                        QString IString = QString::number(i);
                        request.append(IString);
                        request.append("_all");
                        QSqlRecord rec = query.record();
                        int ColumnIndex = rec.indexOf(request);
                        QString DataForResult = query.value(ColumnIndex).toString();
                        result.append(DataForResult);
                        result.append(" ");
                        request = "n";
                        request.append(IString);
                        request.append("_true");
                        ColumnIndex = rec.indexOf(request);
                        DataForResult = query.value(ColumnIndex).toString();
                        result.append(DataForResult);
                        result.append(" ");
                    }
                }
                result.remove(result.length()-1,1);
            }
            return result;
        }
};

#endif // DATABASE_H
