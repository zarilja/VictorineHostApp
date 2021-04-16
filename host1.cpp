#include "host1.h"
#include "ui_host1.h"
#include "mainwidget.h"
#include "hostroom.h"
#include "WebsocketHost.h"

Host1::Host1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::host1)
{
    ui->setupUi(this);
    AdminManager* manager = (AdminManager*)SocketManager::instance(Type::ADMIN);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Host1::onPushButton_3Clicked);
    //connect(this,&Host1::adminCreateSignal,manager,&AdminManager::sendCreate);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Host1::back);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Host1::showHostRoom);
    connect(manager,&AdminManager::recievedCreate,  [=]( QString code,QString admin_id ) { qDebug() << code << " --- " << admin_id; });//Даня сделал сказал делать также что то  спросить у жени нихуя не понятно ААААААААААААААААААААААААААААААААА
}

Host1::~Host1()
{
    delete ui;
}

void Host1::onPushButton_3Clicked()
{

    }


void Host1::back(){
       AdminManager* manager = (AdminManager*)SocketManager::instance(Type::ADMIN);
    MainWidget* w = new MainWidget(parentWidget());
    qobject_cast<QMainWindow*>(parentWidget())->setCentralWidget(w);
    parentWidget()->setFixedSize(w->width(),w->height());
    manager->sendClose();

}
void Host1::showHostRoom(){

    AdminManager* manager = (AdminManager*)SocketManager::instance(Type::ADMIN);
    connect(manager,&AdminManager::recievedCreate,  [=]( QString code,QString admin_id ) {
        qDebug() << code << " --- " << admin_id;
        hostRoom* h = new hostRoom(parentWidget());
        qobject_cast<QMainWindow*>(parentWidget())->setCentralWidget(h);
        parentWidget()->setFixedSize(h->width(),h->height());
    });
   manager->sendCreate("Name");
}

