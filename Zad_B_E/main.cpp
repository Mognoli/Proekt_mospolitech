#include <QCoreApplication>
#include <iostream>
#include <string>

void F1 (int *x, int *y, char z, int *q){
    int i;
    if (z=='+'){
        for (i=0; i<8; i++){
            if (x[i] || y[i])
                q[i]=1;
            else
                q[i]=0;
        }
    }
    else {
        for (i=0; i<8; i++){
            if (x[i] && y[i])
                q[i]=1;
            else
                q[i]=0;
        }

    }
    return;
};

void V (char x, int* r){
    int i;
    switch (x) {
    case 'a':{
        for (i=0; i<4; i++){
            r[i]=0;
            r[i+4]=1;
        }
        break;
    }
    case 'b':{
        //r=new int [8] {0, 0, 1, 1, 0, 0, 1, 1};
        for (i=0; i<8; i+=4){
            for (int j=0; j<2; j++){
            r[i+j]=0;
            r[i+2+j]=1;
            }
        }
        break;
    }
    default:{
        for (i=0; i<8; i+=2){
            r[i]=0;
            r[i+1]=1;
        }
        break;
    }
    }
    return;
};

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
    int *r, *R, *Q, *q;
    r=new int [8];
    R=new int [8];
    Q=new int [8];
    q=new int [8];
    V(s[0], r);
    V(s[2], R);
    F1(r, R, s[1], Q);
    V(s[4], r);
    V(s[6], R);
    F1(r, R, s[5], q);
    F1(Q, q, s[3], Q);
    for (i=0; i<8; i++){
        if(Q[i])
            e++;
        else
            e--;
        std::cout<<Q[i] <<' ';

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
    delete []q;
    delete []Q;
    delete []r;
    delete []R;
}
