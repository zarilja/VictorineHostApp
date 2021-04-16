#ifndef HOSTFIRSTPARTGAME_H
#define HOSTFIRSTPARTGAME_H

#include <QWidget>

namespace Ui {
class hostFirstPartGame;
}

class hostFirstPartGame : public QWidget
{
    Q_OBJECT

public:
    explicit hostFirstPartGame(QWidget *parent = nullptr);
    ~hostFirstPartGame();

private:
    Ui::hostFirstPartGame *ui;
};

#endif // HOSTFIRSTPARTGAME_H
