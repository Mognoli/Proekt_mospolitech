#include "func.h"
#include <iostream>

func::func()
{
    f=0;

}
int func::f1 (int x, int y, char z){
    if (z==')'){
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
    return f;
};

int func::V (char x, char y, int I, int J){
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
    return r;
};

void func::rsr(std::string str){
    int R=0;
    int i, j, k=0;
    int q[4]{0};
    for (i=1; i>=0; i--){
        for (j=1; j>=0; j--){
            f=V(str[6], str[7], i, j);

            f=f1(R, this->f, str[5]);

            R=V(str[0], str[1],  i, j);

            q[k+j]=f1(f, R, str[2]);
        }

        k+=2;

    }
    for (i=0; i<4; i+=2){
        q[i]=f1(q[i], q[i+1], '*');
    }
    f=f1(q[0], q[2], '+');
    return;
};

