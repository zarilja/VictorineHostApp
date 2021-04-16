#ifndef USERSERVER_H
#define USERSERVER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>

class UserTestServer : public QObject
{
    Q_OBJECT
    QWebSocketServer* server;
    QWebSocket* socket;


public:
    explicit UserTestServer(QObject *parent = nullptr);

public slots:
    void connected();
    void onTextMessageRecieve(const QString& message);

signals:

};

#endif // USERSERVER_H
