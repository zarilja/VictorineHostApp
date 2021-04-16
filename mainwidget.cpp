#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "inputroomcod.h"
#include "host1.h"
#include "rules.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWidget::showConnectWindow);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWidget::showHost);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWidget::showRules);
    connect(ui->pushButton_4,&QPushButton::clicked,parent,&QMainWindow::close);
}

MainWidget::~MainWidget()
{
    delete ui;
}
void MainWidget::showConnectWindow(){

    inputcodnumber* i = new inputcodnumber(parentWidget());
    i->show();

}

void MainWidget::showHost(){

    Host1* h = new Host1(parentWidget());
    qobject_cast<QMainWindow*>(parentWidget())->setCentralWidget(h);
    parentWidget()->setFixedSize(h->width(),h->height());
}
void MainWidget::showRules(){
    Rules* r = new Rules();
    r->show();

}
