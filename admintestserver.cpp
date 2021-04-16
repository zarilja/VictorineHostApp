#include "admintestserver.h"
#include <QtWebSockets/QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

AdminTestServer::AdminTestServer()
{
    server = new QWebSocketServer("danya lox",QWebSocketServer::NonSecureMode);
    if (server->listen(QHostAddress("localhost"),4433)){
        connect(server,&QWebSocketServer::newConnection,this,&AdminTestServer::connected);
    }

}

void AdminTestServer::connected()
{
    socket = server->nextPendingConnection();

    connect(socket,&QWebSocket::textMessageReceived, this, &AdminTestServer::onTextMessageRecieve);
}

void AdminTestServer::onTextMessageRecieve(const QString& message)
{
    QJsonObject json = QJsonDocument::fromJson(message.toLocal8Bit()).object();
    QString type = json["type"].toString();
    if (type ==  "create"){
        QJsonObject obj;
        obj["type"] = "create";
        obj["code"] = "ABCDEF";
        obj["admin-id"] = "ec8e7647905945208c0be04e43e3a2e9";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }

    if (type ==  "join"){
        QJsonObject obj;
        obj["type"] = "join";
        obj["code"] = "ABCDEF";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "add_question"){
        QJsonObject obj;
        obj["type"] = "add_question";
        obj["code"] = "123";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "start_round1"){
        QJsonObject obj;
        obj["type"] = "start";
        obj["num"] = 1;
        obj["max_ans"] = 20;
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "join"){
        QJsonObject obj;
        obj["type"] = "join";
        obj["code"] = "ABCDEF";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "start_round2"){
        QJsonObject obj;
        obj["type"] = "start";
        obj["num"] = 2;
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "player_connected"){
        QJsonObject obj;
        obj["type"] = "pl_con";
        obj["team_id"] = "123";
        obj["answers"] = "123";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "get_answers"){
        QJsonObject obj;
        obj["type"] = "ans";
        obj["player_id"] = "123";
        obj["question"] = "Question";
        QJsonArray arr;
        arr.append(QJsonValue("Answer1"));
        arr.append(QJsonValue("Answer2"));
        arr.append(QJsonValue("Answer3"));
        arr.append(QJsonValue("Answer4"));
        obj["answers"] =  arr;
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "close"){
        QJsonObject obj;
        obj["type"] = "close";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }
    if (type ==  "event_code"){
        QJsonObject obj;
        obj["type"] = "event_code";
        obj["err_desc"] ="Error description";
        QJsonDocument doc(obj);
        socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    }


}
