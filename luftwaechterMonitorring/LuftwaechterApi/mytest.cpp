#include "mytest.h"

MyTest::MyTest(QObject *parent) : QObject(parent)
{

}

MyTest::~MyTest()
{

}

void MyTest::test(QString output)
{
    qInfo() << "This is my output: " << output << " exNr: " << m_exNr;
}

int MyTest::exNr() const
{
    return m_exNr;
}

void MyTest::setExNr(int newExNr)
{
    if (m_exNr == newExNr)
        return;
    m_exNr = newExNr;
    emit exNrChanged();
}
