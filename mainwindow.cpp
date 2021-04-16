#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWidget* m = new MainWidget(this);
    this->setCentralWidget(m);
}

MainWindow::~MainWindow()
{
    delete ui;
}




