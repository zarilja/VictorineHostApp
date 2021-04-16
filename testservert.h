#ifndef TESTSERVERT_H
#define TESTSERVERT_H
#include <QObject>
#include <QtWebSockets/QWebSocketServer>

class TestServer: public QObject
{
Q_OBJECT


    QWebSocketServer server;


public:
    TestServer();


};

#endif // TESTSERVERT_H
