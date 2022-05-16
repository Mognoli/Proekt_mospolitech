#ifndef ZADANIEN1_H
#define ZADANIEN1_H

#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QDebug>

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

static QString createAnswer(QString condition){
//    qDebug() << condition;
    std::string s = condition.toStdString();
    std::string result = "";
    int i, e=0;
    int *r, *R, *Q, *q;
    r=new int [8];
    R=new int [8];
    Q=new int [8];
    q=new int [8];
    V(s[0], r);
    V(s[2], R);
    V(s[4], r);
    V(s[6], R);
    F1(r, R, s[1], Q);
    F1(r, R, s[5], q);
    F1(Q, q, s[3], Q);
    for (i=0; i<8; i++){
        if(Q[i])
            e++;
        else
            e--;
//        std::cout<<Q[i] <<' ';
    }
//     std::cout<<std::endl;
     switch (e) {
     case 8:{
         for(i=0; i<2; i++)
         result.append("1 0 ");
         break;
     }
     case -8:{
         for(i=0; i<2; i++)
         result.append("0 1 ");
         break;
     }
     default:{
         result.append("0 0 1 1 ");
         break;
     }
     }
    delete []q;
    delete []Q;
    delete []r;
    delete []R;
    result.pop_back();
    QString qstr = QString::fromStdString(result);
    return qstr;
}

#endif // ZADANIEN1_H
