#ifndef PLAYERROOM_H
#define PLAYERROOM_H

#include <QWidget>

namespace Ui {
class playerroom;
}

class playerroom : public QWidget
{
    Q_OBJECT

signals:
    void joinTeamSignal(QString team_id);
public slots:
    void onPushButton_2Clicked();
public:
    explicit playerroom(QWidget *parent = nullptr);
    ~playerroom();



private:
    Ui::playerroom *ui;
};

#endif // PLAYERROOM_H
