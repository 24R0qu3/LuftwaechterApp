#include "mytest.h"

MyTest::MyTest(QObject *parent) : QObject(parent)
{

}

MyTest::~MyTest()
{

}

void MyTest::test(QString output)
{
    qInfo() << "This is my output: " << output;
}
