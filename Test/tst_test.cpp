
#include <QtTest>
#include "../travelagency.h"

// add necessary includes here

class Test : public QObject
{
    Q_OBJECT

public:
    Test();
    ~Test();

private slots:
    void test_case1();

};

Test::Test()
{

}

Test::~Test()
{

}

void Test::test_case1()
{
    QCOMPARE(15,15);
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
