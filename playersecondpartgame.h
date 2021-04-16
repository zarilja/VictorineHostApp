#ifndef PLAYERSECONDPARTGAME_H
#define PLAYERSECONDPARTGAME_H

#include <QWidget>

namespace Ui {
class playersecondpartgame;
}

class playersecondpartgame : public QWidget
{
    Q_OBJECT

public:
    explicit playersecondpartgame(QWidget *parent = nullptr);
    ~playersecondpartgame();

private:
    Ui::playersecondpartgame *ui;
};

#endif // PLAYERSECONDPARTGAME_H
