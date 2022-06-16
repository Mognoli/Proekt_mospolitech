#include <QCoreApplication>
#include <iostream>
#include <string>
#include "f1f.h"





int main(){
    int i, e=0;;
    srand(time(0));
    std::string s;
    s=char(rand()%3+97);
        s.push_back(char(rand()%2+42));
        s.push_back(char(rand()%3+97));
        s.push_back(char(rand()%2+42));
        s.push_back(char(rand()%3+97));
        s.push_back(char(rand()%2+42));
    s.push_back(char(rand()%3+97));
    std::cout<<s <<std::endl;
    //int *r, *R, *Q, *q;
    F1F r, R, Q, q;
    /*r=new int [8];
    R=new int [8];
    Q=new int [8];
    q=new int [8];*/
    r.V(s[0]);
    R.V(s[2]);
    Q.F1(r, R, s[1]);
    r.V(s[4]);
    R.V(s[6]);
    q.F1(r, R, s[5]);
    Q.F1(Q, q, s[3]);
    for (i=0; i<8; i++){
        if(Q.m[i])
            e++;
        else
            e--;
        std::cout<<Q.m[i] <<' ';

    }
     std::cout<<std::endl;
     switch (e) {
     case 8:{
         for(i=0; i<2; i++)
         std::cout<<1 <<' ' <<0 <<' ';
         break;
     }
     case -8:{
         for(i=0; i<2; i++)
         std::cout<<0 <<' ' <<1 <<' ';
         break;
     }
     default:{
         std::cout<<0 <<' ' <<0 <<' ' <<1 <<' ' <<1 <<' ';
         break;
     }
     }
    /*delete []q;
    delete []Q;
    delete []r;
    delete []R;*/
}
