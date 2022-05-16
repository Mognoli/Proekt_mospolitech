#ifndef CREATECONDITION_H
#define CREATECONDITION_H

#include <QStringList>
#include <QString>

QByteArray createCondition_N1() {
    QString s;
    s=char(rand()%3+97);
        s.push_back(char(rand()%2+42));
        s.push_back(char(rand()%3+97));
        s.push_back(char(rand()%2+42));
        s.push_back(char(rand()%3+97));
        s.push_back(char(rand()%2+42));
        s.push_back(char(rand()%3+97));
    QByteArray result = s.toUtf8();
    return  result;
}

QByteArray createCondition_N2() {
    QByteArray result;
    return result;
}

QByteArray createCondition_N3() {
    QByteArray result;
    return result;
}

QByteArray createCondition_N4() {
    QByteArray result;
    return result;
}


static QByteArray createCondition(int number) {
    QByteArray result;
    if (number == 1) {
        result.append(createCondition_N1());
    }
    else if (number == 2) {

    }
    else if (number == 3) {

    }
    else if (number == 4) {

    }
    return result;
}

#endif // CREATECONDITION_H

