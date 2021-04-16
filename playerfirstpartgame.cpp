#include "playerfirstpartgame.h"
#include "ui_playerfirstpartgame.h"
#include "WebsocketHost.h"

playerfirstpartgame::playerfirstpartgame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerfirstpartgame)
{
    ui->setupUi(this);
    UserManager* manager = (UserManager*)SocketManager::instance(Type::ADMIN);
//    connect(ui->pushButton,&QPushButton::clicked,manager,&UserManager::send1stRoundWrongAnswer);
}

playerfirstpartgame::~playerfirstpartgame()
{
    delete ui;
}
