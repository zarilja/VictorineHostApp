#include "mainwindow.h"

#include <QApplication>
#include "WebsocketHost.h"
#include "admintestserver.h"
#include "userserver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AdminTestServer aserver;
    UserTestServer userver;
    w.show();
    int status = a.exec();
    SocketManager::disposeAll();

    return status;
}
