#include "playersecondpartgame.h"
#include "ui_playersecondpartgame.h"
#include "WebsocketHost.h"
playersecondpartgame::playersecondpartgame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playersecondpartgame)
{
    ui->setupUi(this);
    UserManager* manager = (UserManager*)SocketManager::instance(Type::ADMIN);
//    connect(ui->pushButton,&QPushButton::clicked,manager,&UserManager::send2ndRoundRightAnswer);
}

playersecondpartgame::~playersecondpartgame()
{
    delete ui;
}
