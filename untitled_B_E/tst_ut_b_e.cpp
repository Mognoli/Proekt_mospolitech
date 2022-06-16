#include <QtTest>
#include "D:\User\Desktop\nnn\Zad_B_E\f1f.h"
//#include "D:\User\Desktop\nnn\build-Zad_B_E-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\debug\main.obj"
// add necessary includes here

class ut_b_e : public QObject
{
    Q_OBJECT

public:
    ut_b_e();
    ~ut_b_e();

private slots:
    void test_case1();

};

ut_b_e::ut_b_e()
{

}

ut_b_e::~ut_b_e()
{

}

void ut_b_e::test_case1()
{
    F1F a, b, c, d;
    int* xa = new int [8] {0, 0, 0, 0, 1, 1, 1, 1};
    int* xb= new int [8] {1, 1, 0, 0, 1, 1, 0, 0};
    //int* x= new int [8];
    int* xd= new int [8] {0, 0, 0, 0, 1, 1, 0, 0};
    a.Z(xa);
    b.Z(xb);
    d.Z(xd);
    c.F1(a, b, '*');
    //int x=1;
    QCOMPARE(d.m[1], c.m[1]);
    delete []xa;
    delete []xb;
    delete []xd;
}

QTEST_APPLESS_MAIN(ut_b_e)

#include "tst_ut_b_e.moc"
