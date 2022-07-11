#include <QCoreApplication>
#include <iostream>
#include <string>
#include "func.h"



int main(){
    func x, y;
    srand(time(0));
    std::string s;
    s=char(rand()%2+48);
        s.push_back(char(rand()%3+120));
        s.push_back(char(rand()%2+41));
        s.push_back(char(rand()%5+48));
        s.push_back(char(rand()%3+120));
        s.push_back(char(rand()%2+41));
        s.push_back(char(rand()%5+48));
        s.push_back(char(rand()%3+120));

    std::cout<<s <<std::endl;
    y.rsr(s);
}
