#ifndef PLAYERFIRSTPARTGAME_H
#define PLAYERFIRSTPARTGAME_H

#include <QWidget>

namespace Ui {
class playerfirstpartgame;
}

class playerfirstpartgame : public QWidget
{
    Q_OBJECT

public:
    explicit playerfirstpartgame(QWidget *parent = nullptr);
    ~playerfirstpartgame();

private:
    Ui::playerfirstpartgame *ui;
};

#endif // PLAYERFIRSTPARTGAME_H
