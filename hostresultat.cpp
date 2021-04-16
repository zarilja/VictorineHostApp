#include "hostresultat.h"
#include "ui_hostresultat.h"

hostresultat::hostresultat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hostresultat)
{
    ui->setupUi(this);
}

hostresultat::~hostresultat()
{
    delete ui;
}
