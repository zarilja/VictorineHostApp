#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>

class AdminTestServer: public QObject
{
    Q_OBJECT

    QWebSocketServer* server;
    QWebSocket* socket;

public:
    AdminTestServer();

public slots:
    void connected();
    void onTextMessageRecieve(const QString& message);
};

#endif // TESTSERVER_H
