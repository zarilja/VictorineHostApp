#include "hostfirstpartgame.h"
#include "ui_hostfirstpartgame.h"


hostFirstPartGame::hostFirstPartGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hostFirstPartGame)
{
    ui->setupUi(this);

}

hostFirstPartGame::~hostFirstPartGame()
{
    delete ui;
}
