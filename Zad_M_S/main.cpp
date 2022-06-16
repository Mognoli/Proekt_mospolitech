#include <QCoreApplication>
#include <iostream>
#include <string>
#include "ms.h"



int main(){
    ms x, y;
    int i;
    srand(time(0));
    std::string s;
    s=char(rand()%2+48);
        s.push_back(char(rand()%3+120));
        s.push_back(char(rand()%3+41));
        s.push_back(char(rand()%2+48));
        s.push_back(char(rand()%3+120));
        s.push_back(char(rand()%3+41));
        s.push_back(char(rand()%2+48));
        s.push_back(char(rand()%3+120));
    //s.push_back(char(rand()%3+97));*/
    //std::string s="0y)0z+1x";
    s=x.A(s);
    std::cout<<s <<std::endl;
    //int W=0, R=0;
    x.T(s);
    for (i=0; i<=6; i+=3){
        if(s[i]=='0')
            s[i]='1';
        else
            s[i]='0';
    }
    //std::cout<<"kkkkkkkkkkkkkkkkkk"<< std::endl;
    //std::cout<<s <<std::endl;
    y.T(s);
    if (x.f==y.f)
        std::cout<<0 <<' ' <<0 <<' ' <<1 <<' ' <<1 <<' ';
    else{
        if (x.f){
            for(i=0; i<2; i++)
            std::cout<<1 <<' ' <<0 <<' ';
        }
        else{
            for(i=0; i<2; i++)
            std::cout<<0 <<' ' <<1 <<' ';
        }
    }
    return 0;
}
