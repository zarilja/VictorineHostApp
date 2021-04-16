#include "hostroom.h"
#include "ui_hostroom.h"
#include "host1.h"
#include "hostfirstpartgame.h"
#include "WebsocketHost.h"

hostRoom::hostRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hostRoom)
{
    ui->setupUi(this);
    AdminManager* manager = (AdminManager*)SocketManager::instance(Type::ADMIN);
//    connect(ui->pushButton,&QPushButton::clicked,manager,&AdminManager::sendStartRound);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&hostRoom::back);
    connect(ui->pushButton,&QPushButton::clicked,this,&hostRoom::showHostFirstPartGame);
}

hostRoom::~hostRoom()
{
    delete ui;
}
void hostRoom::back(){
    AdminManager* manager = (AdminManager*)SocketManager::instance(Type::ADMIN);


        Host1 * h = new Host1 (parentWidget());
        qobject_cast<QMainWindow*>(parentWidget())->setCentralWidget(h);
        parentWidget()->setFixedSize(h->width(),h->height());
    }

void hostRoom::showHostFirstPartGame(){
    AdminManager* manager = (AdminManager*)SocketManager::instance(Type::ADMIN);
    connect(manager,&AdminManager::recievedStartRound1,  [=]( int num ) {
        qDebug() << num;
        hostFirstPartGame* h = new hostFirstPartGame(parentWidget());
        qobject_cast<QMainWindow*>(parentWidget())->setCentralWidget(h);
        parentWidget()->setFixedSize(h->width(),h->height());
    });

}
