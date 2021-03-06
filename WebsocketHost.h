#ifndef WEBSOCKETHOST_H
#define WEBSOCKETHOST_H
#include <QtWebSockets/QWebSocket>
#include <QList>

enum class Type{
    USER,
    ADMIN
};


struct Answer{
    int key;
    QString value;
};

class UserManager;
class AdminManager;

class SocketManager{
    static UserManager *user;
    static AdminManager *admin;
protected:
    QWebSocket *socket;
public:
    // Вернуть студента или препода.
    static SocketManager* instance(Type type);
    static void disposeAll();
};

// Студент
class UserManager: public QObject, public SocketManager{
    Q_OBJECT

public:
    UserManager();
    void sendJoin (QString roomCode, QString name);
    void sendJoinTeam (QString team_id);
    void sendGetTeams ();
    void send1stRoundWrongAnswer (QString pl_id,QString question_id,QString string);
    void send2ndRoundRightAnswer (QString pl_id,QString question_id,QString string);

public slots:
    void onConnected();
    void onDisconnected();
    void onMessageRecieved(const QString& message);


signals:
    void recievedJoin(QString pl_id);
    void recievedGet_teams(QList<QString> team_ids);
    void recievedJoinTeam(QString team_id);
    void recieved1sRoundGetWrongQuest(QList<QString>question_ids, QStringList string);
    void recievedTimerElapsed ();
    void recievedGetAnswers (QString quetsion, QString question_id, QList<Answer> answers);
};


// Препод
class AdminManager: public QObject, public SocketManager{
    Q_OBJECT

public:
    AdminManager();



public slots:
    void onConnected();
    void onDisconnected();
    void onMessageRecieved(const QString& message);
    void sendCreate (QString name);
    void sendJoin (QString admin_id);
    void sendAddQuestion (QString question,QString answer);
    void sendStartRound (int num, int timer);

signals:
    void recievedError(QString err_desc);
    void recievedCreate (QString code,QString admin_id);
    void recievedJoin (QString code);
    void recievedAddQuestion (int question_id);
    void recievedStartRound1 (int max_ans);
    void recievedStartRound2 ();
    void recievedPlayerConnected (int team_id, int pl_id);
    void recievedGetAnswers (int team_id, QString question, QStringList answers);
    void recivedClose();


};


#endif // WEBSOCKETHOST_H
