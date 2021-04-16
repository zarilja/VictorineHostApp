QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets websockets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    WebsocketHost.cpp \
    admintestserver.cpp \
    host1.cpp \
    hostfirstpartgame.cpp \
    hostresultat.cpp \
    hostroom.cpp \
    hostsecondpartgame.cpp \
    inputroomcod.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    playerfirstpartgame.cpp \
    playerroom.cpp \
    playersecondpartgame.cpp \
    rules.cpp \
    userserver.cpp

HEADERS += \
    WebsocketHost.h \
    admintestserver.h \
    host1.h \
    hostfirstpartgame.h \
    hostresultat.h \
    hostroom.h \
    hostsecondpartgame.h \
    inputroomcod.h \
    mainwidget.h \
    mainwindow.h \
    playerfirstpartgame.h \
    playerroom.h \
    playersecondpartgame.h \
    rules.h \
    userserver.h

FORMS += \
    host1.ui \
    hostfirstpartgame.ui \
    hostresultat.ui \
    hostroom.ui \
    hostsecondpartgame.ui \
    inputroomcod.ui \
    mainwidget.ui \
    mainwindow.ui \
    playerfirstpartgame.ui \
    playerroom.ui \
    playersecondpartgame.ui \
    rules.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
