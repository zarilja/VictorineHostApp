#ifndef USERTESTSERVER_H
#define USERTESTSERVER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>

class UserTestServer: public QObject
{
    Q_OBJECT

    QWebSocketServer* server;
    QWebSocket* socket;

public:
    UserTestServer();

public slots:
    void connected();
    void onTextMessageRecieve(const QString& message);
};

#endif // TESTSERVER_H
