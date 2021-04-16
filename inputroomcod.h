#ifndef INPUTCODNUMBER_H
#define INPUTCODNUMBER_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class inputcodnumber;
}

class inputcodnumber : public QWidget
{
    Q_OBJECT

public:
    explicit inputcodnumber(QWidget *parent = nullptr);
    ~inputcodnumber();

private:
    Ui::inputcodnumber *ui;
    QWidget* mainwindow;
public slots:
    void showPlayerRoom();
};

#endif // INPUTCODNUMBER_H
