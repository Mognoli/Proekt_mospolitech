#include <QtTest>
#include "../Task5.h"

class Test5 : public QObject
{
    Q_OBJECT

public:
    Test5();
    ~Test5();

private slots:
    void test_case1();
    void test_case2();

};

Test5::Test5()
{

}

Test5::~Test5()
{

}


void Test5::test_case1() {
    Task5 task1("10010111");
    task1.solveTask();
    // ответ пользователя состоит из нескольких строк (тупиковых ДНФ), каждая строка имеет несколько подстрок, поэтому имеет вид списка списков строк
    std::set<std::set<std::string>> answer = {{"xy", "xz", "yz", "-x-y-z"}}; // 1 тупиковая ДНФ
    QCOMPARE(answer, task1.getAnswer());
}

void Test5::test_case2() {
    Task5 task2("11011011");
    task2.solveTask();
    std::set<std::set<std::string>> answer = {{"xy", "-y-z", "-xz"},
    {"x-z", "-x-y", "yz"},
    {"x-z", "-y-z", "-xz", "yz"},
    {"xy", "x-z", "-x-y", "-xz"},
    {"xy", "-x-y", "-y-z", "yz"}}; // 5 тупиковых ДНФ
    QCOMPARE(answer, task2.getAnswer());
}

QTEST_APPLESS_MAIN(Test5)

#include "tst_test5.moc"




