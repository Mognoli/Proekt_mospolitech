#include "ms.h"
#include <iostream>

ms::ms()
{
    f=0;

}
int ms::F1 (int x, int y, char z){
    //int q;
    //std::cout<< x <<" " <<y;
    if (z=='+'){
        if (x || y)
            this->f=1;
        else
            this->f=0;
    }
    else {
        if (x && y)
            this->f=1;
        else
           this->f=0;
    }
    //std::cout <<std::endl <<x <<" " <<y <<" " <<q <<std::endl;;
    return f;
};

int ms::V (char x, char y, int I, int J){
    int r;
    switch (y) {
    case 'x':{
        if (I)
            r=0;
        else
            r=1;
        break;
    }
    case 'y':{
        if (J)
            r=0;
        else
            r=1;
        break;
    }
    default:{
        if (!I && !J)
            r=1;
        else
            r=0;
        break;
    }
    }
    if(x=='1'){
        if(r)
            r=0;
        else
            r=1;
    }
    //std::cout<<"___" <<r;
    return r;
};

void ms::T(std::string s){
    int R=0;
    //int u=9;
    int i, j, k=0;
    int q[4]{0};
    for (i=1; i>=0; i--){
        for (j=1; j>=0; j--){
            f=V(s[6], s[7], i, j);
            //V(s[3], s[4], R, i, j);
            //std::cout<<"(((((((  " <<k <<" ";
            f=F1(R, this->f, s[5]);
            //std::cout<<"(((((((  " <<r <<" ";
            R=V(s[0], s[1],  i, j);
            //std::cout<<"(((((((  " <<r <<" ";
            q[k+j]=F1(f, R, s[2]);
            //std::cout<<"(((((((  " <<R <<" ";
            //std::cout<<std::endl;
            //std::cout<<"+++++++++++++" <<u <<std::endl;
        }

        k+=2;

    }
    for (i=0; i<4; i+=2){
        q[i]=F1(q[i], q[i+1], '*');
    }
    f=F1(q[0], q[2], '+');
    //std::cout<<"   " <<r <<std::endl;
    return;
};

std::string ms::A(std::string s){
    for(int h=0; h<=4; h+=3){
        if (s[2+h]==')'){
            s[2+h]='+';
            if(s[h]=='0')
                s[h]='1';
            else
                s[h]='0';
        }
    }
    //std::cout <<"   1  " << s << "        ";
    return s;
}
