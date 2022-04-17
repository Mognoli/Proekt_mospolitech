#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include "connecttoserver.h"

class ConnectServer;

class ConnectServerDestroyer
{
    private:
        ConnectServer * p_instance;
    public:
        ~ConnectServerDestroyer() { delete p_instance;}
        void initialize(ConnectServer* p){p_instance = p;}
};


class ConnectServer
{
    private:
        static ConnectServer* p_instance;
        static ConnectServerDestroyer destroyer;
        static ConnectToServer *Server;
    protected:
        ConnectServer(){}
        ConnectServer(const ConnectServer& );
        ConnectServer& operator = (ConnectServer&);
        ~ConnectServer() {delete Server;}
        friend class SingletonDestroyer;
    public:
        static ConnectServer* getInstance(){
            Server = new ConnectToServer();
            if (!p_instance)
            {
                p_instance = new ConnectServer();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        static QString ToServer(QString toServerMesseng){
            return Server->toServer(toServerMesseng);
        }
};

#endif // CONNECTSERVER_H
