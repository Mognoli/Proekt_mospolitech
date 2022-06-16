#include <QtTest>
#include "D:\User\Desktop\nnn\Zad_M_S\ms.h"
// add necessary includes here

class ut_M_S : public QObject
{
    Q_OBJECT

public:
    ut_M_S();
    ~ut_M_S();

private slots:
    void test_case1();

};

ut_M_S::ut_M_S()
{

}

ut_M_S::~ut_M_S()
{

}

void ut_M_S::test_case1()
{
    ms x;
    std::string s="0y)0z+1x";
    std::string c="1y+0z+1x";
    s=x.A(s);
    QCOMPARE(c, s);
}

QTEST_APPLESS_MAIN(ut_M_S)

#include "tst_ut_m_s.moc"
