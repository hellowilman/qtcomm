#ifndef COMMMODULE_H
#define COMMMODULE_H

#include <QObject>
#include <QtNetwork>
#include <QThread>

/**
 * @brief The CommModule class
 * this class implement the local network communication in a standalone threadlocaleinfostruct
 * this implementation is used a Udp socket to sending/receiving data
 */
class CommModule : public QObject
{
    Q_OBJECT
public:
    explicit CommModule(QObject *parent = 0);
    explicit CommModule(int const portIn, int const portOut);
    ~CommModule();

    // getter and setter
    int getNPortIn() const;
    void setNPortIn(int value);
    int getNPortOut() const;
    void setNPortOut(int value);

signals:
    /**
     * @brief sigDataReceived emit when the there is data
     */
    void sigDataReceived(QByteArray);
    /**
     * @brief sigInit, emit if we want to init the network
     */
    void sigInit();
    /**
     * @brief sigSendDatagram emit if we want to send datagram
     */
    void sigSendDatagram(QByteArray );

public slots:
    /**
     * @brief sendDatagram for sending data via network
     * @return
     */
    int sendDatagram(QByteArray);

private:
    QUdpSocket *sender;
    QUdpSocket *receiver;
    QThread thread;
    int nPortIn;
    int nPortOut;



private slots:
    void readPendingDatagrams();
    void start();
    void stop();

};

#endif // COMMMODULE_H
