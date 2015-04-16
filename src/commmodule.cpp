#include "commmodule.h"

CommModule::CommModule(QObject *parent) :
    QObject(parent),
    nPortIn(12344),nPortOut(12345),
    receiver(0),sender(0)
{
    moveToThread(&thread);
    connect(this,SIGNAL(sigInit()),
            this,SLOT(start()));
    connect(this,SIGNAL(sigSendDatagram(QByteArray)),
            this,SLOT(sendDatagram(QByteArray)));
    connect(&thread,SIGNAL(finished()),
            this,SLOT(stop()));
    thread.start();

}

CommModule::~CommModule()
{

}

void CommModule::readPendingDatagrams()
{
    QByteArray datagram;
    while (receiver->hasPendingDatagrams()) {
         datagram.resize(receiver->pendingDatagramSize());
         receiver->readDatagram(datagram.data(), datagram.size());
    }
    emit this->sigDataReceived(datagram);
}


int CommModule::sendDatagram(QByteArray datagram)
{
    return sender->writeDatagram(datagram.data(),datagram.size(),
           QHostAddress::LocalHost,nPortOut);
}
int CommModule::getNPortOut() const
{
    return nPortOut;
}

void CommModule::setNPortOut(int value)
{
    nPortOut = value;
}

int CommModule::getNPortIn() const
{
    return nPortIn;
}

void CommModule::setNPortIn(int value)
{
    nPortIn = value;
}


void CommModule::start()
{
    stop();
    receiver = new QUdpSocket();
    sender = new QUdpSocket();
    receiver->bind(QHostAddress::LocalHost,nPortIn);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(readPendingDatagrams()));

}

void CommModule::stop()
{
    if(receiver){delete receiver;receiver = 0;}
    if(sender){delete sender;sender = 0;}
}

