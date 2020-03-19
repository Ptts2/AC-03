#ifndef ALGORITMO2WINDOW_H
#define ALGORITMO2WINDOW_H

#include <QDialog>

namespace Ui {
class Algoritmo2Window;
}

class Algoritmo2Window : public QDialog
{
    Q_OBJECT

public:
    explicit Algoritmo2Window(QWidget *parent = nullptr);
    ~Algoritmo2Window();

private:
    Ui::Algoritmo2Window *ui;
};

#endif // ALGORITMO2WINDOW_H
