#ifndef HOSTSECONDPARTGAME_H
#define HOSTSECONDPARTGAME_H

#include <QWidget>

namespace Ui {
class hostSecondpartgame;
}

class hostSecondpartgame : public QWidget
{
    Q_OBJECT

public:
    explicit hostSecondpartgame(QWidget *parent = nullptr);
    ~hostSecondpartgame();

private:
    Ui::hostSecondpartgame *ui;
};

#endif // HOSTSECONDPARTGAME_H
