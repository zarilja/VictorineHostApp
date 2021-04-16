#include "userserver.h"
#include <QtWebSockets/QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


UserTestServer::UserTestServer(QObject *parent) : QObject(parent)
{
    server = new QWebSocketServer("danya lox",QWebSocketServer::NonSecureMode);
    if (server->listen(QHostAddress("localhost"),4434)){
        connect(server,&QWebSocketServer::newConnection,this,&UserTestServer::connected);
    }
}


void UserTestServer::connected()
{
    socket = server->nextPendingConnection();

    connect(socket,&QWebSocket::textMessageReceived, this, &UserTestServer::onTextMessageRecieve);
}


void UserTestServer::onTextMessageRecieve(const QString& message)
{
    QJsonObject json = QJsonDocument::fromJson(message.toLocal8Bit()).object();
    QString type = json["type"].toString();

    if (type ==  "join"){
        QJsonObject obj;
        obj["type"] = "join";
        obj["pl_id"] = "123";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "get_t"){
        QJsonObject obj;
        obj["type"] = "get_t";
        QJsonArray arr;
        arr.append(QJsonValue("123"));
        arr.append(QJsonValue("122"));
        arr.append(QJsonValue("121"));
        obj["team_ids"] =  arr;
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "join_t"){
        QJsonObject obj;
        obj["type"] = "join_t";
        obj["team_id"] = "123";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "wr_qst"){
        QJsonObject obj;
        obj["type"] = "wr_qst";
        QJsonArray arr;
        arr.append(QJsonValue("123"));
        arr.append(QJsonValue("122"));
        obj["question_id"] =  arr;
        QJsonArray arr2;
        arr.append(QJsonValue("123"));
        arr.append(QJsonValue("122"));
        obj["string"] =  arr2;
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "timer_elapsed"){
        QJsonObject obj;
        obj["type"] = "timer_elapsed";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "get_answers"){
        QJsonObject obj;
        obj["type"] = "ans";
        obj["player_id"] = "123";
        obj["question"] = "Question";
        QJsonArray arr;
        QJsonObject o1;
        o1["key"] = 0;
        o1["value"] = "Answer";
        arr.append(o1);
        QJsonObject o2;
        o1["key"] = 1;
        o1["value"] = "Answer";
        arr.append(o2);
        QJsonObject o3;
        o1["key"] = 2;
        o1["value"] = "Answer";
        arr.append(o3);
        QJsonObject o4;
        o1["key"] = 3;
        o1["value"] = "Answer";
        arr.append(o4);
        obj["answers"] = arr;
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }


}
