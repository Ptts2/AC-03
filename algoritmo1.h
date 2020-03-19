#ifndef ALGORITMO1_H
#define ALGORITMO1_H

#include <QWidget>

namespace Ui {
class Algoritmo1;
}

class Algoritmo1 : public QWidget
{
    Q_OBJECT

public:
    explicit Algoritmo1(QWidget *parent = nullptr);
    ~Algoritmo1();

private:
    Ui::Algoritmo1 *ui;
};

#endif // ALGORITMO1_H
