#ifndef HOSTROOM_H
#define HOSTROOM_H

#include <QWidget>

namespace Ui {
class hostRoom;
}

class hostRoom : public QWidget
{
    Q_OBJECT

public:
    explicit hostRoom(QWidget *parent = nullptr);
    ~hostRoom();

private:
    Ui::hostRoom *ui;
public slots:
    void back();
    void showHostFirstPartGame();
};


#endif // HOSTROOM_H
