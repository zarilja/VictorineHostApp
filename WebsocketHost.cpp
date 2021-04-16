#include "WebsocketHost.h"
#include "QJsonObject"
#include "QJsonDocument"
#include <QJsonArray>
#include <QStringList>

UserManager* SocketManager::user = nullptr;
AdminManager* SocketManager::admin = nullptr;

SocketManager* SocketManager::instance(Type type){
    switch (type) {
    case Type::ADMIN:
        if(!SocketManager::admin)
            SocketManager::admin = new AdminManager();
        return SocketManager::admin;
        break;
    case Type::USER:
        if(!SocketManager::user)
            SocketManager::user = new UserManager();
        return SocketManager::user;
        break;
    }
}

void SocketManager::disposeAll(){
    delete SocketManager::admin;
    delete SocketManager::user;
    SocketManager::user = nullptr;
    SocketManager::admin = nullptr;
}

UserManager::UserManager(){
    socket = new QWebSocket();
    connect(socket,&QWebSocket::connected,this,&UserManager::onConnected);
    connect(socket,&QWebSocket::disconnected,this,&UserManager::onDisconnected);
    socket->open(QUrl(QStringLiteral("ws://79.111.29.128:8080/user")));

}

void UserManager::onConnected()
{
    qDebug() << "WebSocket connected";
    connect(socket,&QWebSocket::textMessageReceived,this,&UserManager::onMessageRecieved);

}

void UserManager::onDisconnected()
{

}

void UserManager::onMessageRecieved(const QString& message)
{
    QJsonObject json = QJsonDocument::fromJson(message.toLocal8Bit()).object();
    QString type = json["type"].toString();
    if (type == "join"){
        QString pl_id = json["pl_id"].toString();
        emit recievedJoin(pl_id);
    }
    else if(type == "get_t"){
        QJsonArray arr = json["team-ids"].toArray();
        QList<QString> list;
        for (int i = 0; i < arr.size(); i++){
            list.append(arr.at(i).toString());
        }
        QJsonArray arr2 = json["team-names"].toArray();
        QList<QString> list2;
        for (int i = 0; i < arr2.size(); i++){
            list2.append(arr2.at(i).toString());
        }
        emit recievedGet_teams(list2);

        //connect(manager,&UserManager::recievedGet_teams,  [=]( QList<QString> list ) {
           // for (int i = 0; i < list.size(); i++){

           // }
       // });


    }else if(type == "join_t"){
        QString team_id= json["team_id"].toString();
        emit recievedJoinTeam(team_id);
    }else if(type == "wr-qst"){
        QJsonArray arr = json["question-id"].toArray();
        QList<QString> ids_list;
        for (int i = 0; i < arr.size(); i++){
            ids_list.append(arr.at(i).toString());
        }

        QJsonArray arr2 = json["string"].toArray();
        QStringList string_list;
        for (int i = 0; i < arr2.size(); i++){
            string_list.append(arr2.at(i).toString());
        }


        emit recieved1sRoundGetWrongQuest(ids_list,string_list);
    }else if(type == "timer-elapsed"){
        emit recievedTimerElapsed();
    }//else if(type == "rend"){
        // /////////////////////////int num =1;
       // emit recievedTimerElapsed();

        else if(type == "ans"){
        QString question = json["question"].toString();
        QString question_id= json["question_id"].toString();
        QJsonArray arr = json["answers"].toArray();
        QList<Answer> list;
        for (int i = 0; i < arr.size(); i++){
            QJsonObject obj = arr.at(i).toObject();
            Answer a{obj["key"].toInt(),obj["value"].toString()};
            list.append(a);
        }



        emit recievedGetAnswers(question,question_id,list);
    }else {



    }
}
void AdminManager::onMessageRecieved(const QString& message)
{
    QJsonObject json = QJsonDocument::fromJson(message.toLocal8Bit()).object();
    QString type = json["type"].toString();
    if (type == "event_code"){
        QString err_desc = json["err_desc"].toString();
        emit recievedError(err_desc);
    }else if (type == "create"){
        QString code = json["code"].toString();
        QString admin_id= json["admin_id"].toString();
        emit recievedCreate(code,admin_id);
    }else if (type == "join"){
        QString code = json["code"].toString();
        emit recievedJoin(code);
    }else if (type == "add_question"){
        int question_id = json["question_id"].toInt();
        emit recievedAddQuestion(question_id);
    }else if (type == "start"){
        int num = json["num"].toInt();
        if (num==1){
            int max_ans = json["max_ans"].toInt();
            emit recievedStartRound1(max_ans);
        }else if(num==2){
            emit recievedStartRound2();
        }
    }else if (type == "pl_con"){
        int team_id = json["team_id"].toInt();
        int pl_id = json["pl_id"].toInt();
        emit recievedPlayerConnected(team_id,pl_id);
    }else if (type == "ans"){
        int team_id = json["team_id"].toInt();
        QString question = json["Question"].toString();
        QJsonArray arr = json["answers"].toArray();
        QStringList string_list;
        for (int i = 0; i < arr.size(); i++){
            string_list.append(arr.at(i).toString());
        }
        emit recievedGetAnswers(team_id,question,string_list);
    }else if(type == "close"){
    emit recivedClose();
    }else{

    }

}

void UserManager::sendJoin(QString roomCode, QString name)
{
    QJsonObject json;
    json["type"] = "join";
    json["code"] = roomCode;
       json["nick"] = name;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

void UserManager::sendJoinTeam(QString team_id)
{
    qDebug() << "sendJoinTeam";
    QJsonObject json;
    json["type"] = "join-t";
    json["team_id"]=team_id;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

void UserManager::sendGetTeams()
{
    QJsonObject json;
    json["type"] = "get-t";
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

void UserManager::send1stRoundWrongAnswer(QString pl_id, QString question_id, QString string)
{
    QJsonObject json;
    json["type"] = "wr-ans";
    json["pl_id"]=pl_id;
    json["question_id"]=question_id;
    json["string"]=string;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

void UserManager::send2ndRoundRightAnswer(QString pl_id, QString question_id, QString string)
{
    QJsonObject json;
    json["type"] = "r-ans";
    json["pl_id"]=pl_id;
    json["question_id"]=question_id;
    json["string"]=string;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

AdminManager::AdminManager()
{
    socket = new QWebSocket();
    connect(socket,&QWebSocket::connected,this,&AdminManager::onConnected);
    connect(socket,&QWebSocket::disconnected,this,&AdminManager::onDisconnected);
    socket->open(QUrl(QStringLiteral("ws://79.111.29.128:8080/admin")));
}

void AdminManager::onConnected()
{
    qDebug() << "WebSocket connected";
    connect(socket,&QWebSocket::textMessageReceived,this,&AdminManager::onMessageRecieved);
}

void AdminManager::onDisconnected()
{

}

void AdminManager::sendCreate(QString name)
{
    qDebug() << "sendCreate";
    // Создание json'ки
    QJsonObject json;
    // Добавляешь в json'ку нужные данные
    json["type"] = "create";
    json["nick"] = name;

    // Создаю документ(текстовый вид json'ки)
    QJsonDocument doc(json);
    // Отправляешь документ
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));

}

void AdminManager::sendJoin(QString admin_id)
{
    QJsonObject json;
    json["type"] = "join";
    json["admin_id"]=admin_id;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

void AdminManager::sendAddQuestion(QString question, QString answer)
{
    QJsonObject json;
    json["type"] = "add-question";
    json["question"]=question;
    json["answer"]=answer;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}

void AdminManager::sendStartRound(int num, int timer)
{
    QJsonObject json;
    json["type"] = "start";
    json["num"]=num;
    json["timer"]=timer;
    QJsonDocument doc(json);
    socket->sendTextMessage(doc.toJson(QJsonDocument::Compact));
}
