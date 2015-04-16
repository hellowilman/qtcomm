#ifndef TEST_COMM_H
#define TEST_COMM_H

#include <QObject>
#include "commmodule.h"

class test_comm : public QObject
{
    Q_OBJECT
public:
    explicit test_comm(QObject *parent = 0);
    ~test_comm();

signals:

public slots:
    void onDataReceived(QByteArray);
private:
    CommModule comm;
};

#endif // TEST_COMM_H
