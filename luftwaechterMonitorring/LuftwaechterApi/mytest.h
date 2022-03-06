#ifndef MYTEST_H
#define MYTEST_H

#include <QObject>
#include <QDebug>

class MyTest : public QObject
{
    Q_OBJECT
    int m_exNr = 0;

public:
    explicit MyTest(QObject *parent = nullptr);
    ~MyTest();
    Q_INVOKABLE void test(QString output);

    Q_PROPERTY(int exNr READ exNr WRITE setExNr NOTIFY exNrChanged)

    int exNr() const;
    void setExNr(int newExNr);

signals:

    void exNrChanged();
};

#endif // MYTEST_H
