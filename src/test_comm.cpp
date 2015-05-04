#include "test_comm.h"

test_comm::test_comm(QObject *parent) : QObject(parent)
{
    // initial the network, the comm will use port 12344 (send) and 12345 (receive)
   comm.setNPortIn(12311);
   comm.setNPortOut(12322);
   emit comm.sigInit();
   qDebug()<<"Port 12311 and 12322 is used for communication!!";
    // handle the received data
   connect(&comm,SIGNAL(sigDataReceived(QByteArray)),
           this,SLOT(onDataReceived(QByteArray)));
   // send data
   emit comm.sigSendDatagram("this message from MainWindows");
}

test_comm::~test_comm()
{

}

void test_comm::onDataReceived(QByteArray data)
{
    qDebug()<<"Received: "<< data;
    emit comm.sigSendDatagram("Echo:"+data);
}

