#ifndef MYTEST_H
#define MYTEST_H

#include <QObject>
#include <QDebug>

class MyTest : public QObject
{
    Q_OBJECT
public:
    explicit MyTest(QObject *parent = nullptr);
    ~MyTest();
    Q_INVOKABLE void test(QString output);

signals:

};

#endif // MYTEST_H
