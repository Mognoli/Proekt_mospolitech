#include "f1f.h"

F1F::F1F()
{

}

void F1F::Z (int* x){
    for (int i=0; i<8; i++)
        this->m[i]=x[i];
    return;
}

void F1F::F1 (F1F x, F1F y, char z)  {
    int i;
    if (z=='+'){
        for (i=0; i<8; i++){
            if (x.m[i] || y.m[i])
                this->m[i]=1;
            else
                this->m[i]=0;
        }
    }
    else {
        for (i=0; i<8; i++){
            if (x.m[i] && y.m[i])
                this->m[i]=1;
            else
                this->m[i]=0;
        }

    }
    return;
};

void F1F::V (char x){
    int i;
    switch (x) {
    case 'a':{
        for (i=0; i<4; i++){
            this->m[i]=0;
            this->m[i+4]=1;
        }
        break;
    }
    case 'b':{
        //r=new int [8] {0, 0, 1, 1, 0, 0, 1, 1};
        for (i=0; i<8; i+=4){
            for (int j=0; j<2; j++){
            this->m[i+j]=0;
            this->m[i+2+j]=1;
            }
        }
        break;
    }
    default:{
        for (i=0; i<8; i+=2){
            this->m[i]=0;
            this->m[i+1]=1;
        }
        break;
    }
    }
    return;
};

F1F::~F1F() {
    //delete [] m;
}
