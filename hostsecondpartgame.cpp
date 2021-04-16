#include "hostsecondpartgame.h"
#include "ui_hostsecondpartgame.h"

hostSecondpartgame::hostSecondpartgame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hostSecondpartgame)
{
    ui->setupUi(this);
}

hostSecondpartgame::~hostSecondpartgame()
{
    delete ui;
}
