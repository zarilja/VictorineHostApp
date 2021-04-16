#include "inputroomcod.h"
#include "ui_inputcodnumber.h"
#include "playerroom.h"
#include "WebsocketHost.h"
#include <QJsonObject>
#include <QJsonDocument>

inputcodnumber::inputcodnumber(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::inputcodnumber)
{
    this->mainwindow = parentWidget();
    this->setParent(nullptr);

    ui->setupUi(this);

    //connect(ui->pushButton,&QPushButton::clicked,manager,&UserManager::sendJoin);
    connect(ui->pushButton,&QPushButton::clicked,this,&inputcodnumber::showPlayerRoom);
}

inputcodnumber::~inputcodnumber()
{
    delete ui;
}
    void inputcodnumber::showPlayerRoom(){

        UserManager* manager = (UserManager*)SocketManager::instance(Type::USER);
        connect(manager,&UserManager::recievedJoin,  [=]( QString code,QString admin_id ) {
            qDebug() << code << " --- " << admin_id;
            playerroom* h = new playerroom(this->mainwindow);
            qobject_cast<QMainWindow*>(this->mainwindow)->setCentralWidget(h);
            this->mainwindow->setFixedSize(h->width(),h->height());
            this->close();
        });

        manager->sendJoin(ui->lineEdit->text(),"Ilya lox");


    }

