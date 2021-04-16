#include "playerroom.h"
#include "ui_playerroom.h"
#include "WebsocketHost.h"



playerroom::playerroom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerroom)
{
    ui->setupUi(this);

    UserManager* manager = (UserManager*)SocketManager::instance(Type::ADMIN);
//    connect(ui->pushButton,&QPushButton::clicked,manager,&UserManager::sendJoinTeam);
    connect(ui->pushButton,&QPushButton::clicked,this,&playerroom::onPushButton_2Clicked);
    connect(this,&playerroom::joinTeamSignal,manager,&UserManager::sendJoinTeam);
}

void playerroom::onPushButton_2Clicked()
{
        emit joinTeamSignal("TestTeam");
    }

playerroom::~playerroom()
{
    delete ui;
}
