#ifndef HOSTRESULTAT_H
#define HOSTRESULTAT_H

#include <QWidget>

namespace Ui {
class hostresultat;
}

class hostresultat : public QWidget
{
    Q_OBJECT

public:
    explicit hostresultat(QWidget *parent = nullptr);
    ~hostresultat();

private:
    Ui::hostresultat *ui;
};

#endif // HOSTRESULTAT_H
