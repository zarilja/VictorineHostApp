#ifndef HOST1_H
#define HOST1_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class host1;
}

class Host1 : public QWidget
{
    Q_OBJECT

public:
    explicit Host1(QWidget *parent = nullptr);
    ~Host1();

private:
    Ui::host1 *ui;

signals:
 //   void adminCreateSignal(QString name);
public slots:
    void onPushButton_3Clicked();


public slots:
    void back();
    void showHostRoom();
};

#endif // HOST1_H
