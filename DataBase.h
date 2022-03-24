#ifndef DATABASE_H
#define DATABASE_H

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

        QSqlDatabase db;
    protected:
        DataBase(){}
        DataBase(const DataBase& );
        DataBase& operator = (DataBase &);
        ~DataBase() {
            p_instance->db.close(); // Закрыть БД
        }
        friend class SingletonDestroyer;
    public:
        static DataBase* getInstance(){
            if (!p_instance)
            {
                // создать и открыть БД
                p_instance = new DataBase();
                p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
                p_instance->db.setDatabaseName("DataBaseForServer");

                if (!p_instance->db.open())
                    qDebug() << p_instance->db.lastError().text();

                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

// Создает таблицу
        static QString StartDataBase(){
            QSqlQuery query(p_instance->db);
            query.exec("CREATE TABLE User("
                       "login VARCHAR(20) NOT NULL, "
                       "password VARCHAR(20) NOT NULL"
                       "email VARCHAR(20) NOT NULL, "
                       ")");
            return "";
        };

        static QString AddLogAndPas(QString login, QString password, QString email) {
            QSqlQuery query(p_instance->db);
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
            if (query.value(LoginIndex) == NULL) return "no such user";
                    else {
                QString TruePass = query.value(PasswordIndex).toString();
                if (TruePass != password) return "False";
                else return "true";
            }
        };
};

#endif // DATABASE_H
