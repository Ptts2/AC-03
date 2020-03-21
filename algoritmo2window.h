#ifndef ALGORITMO2WINDOW_H
#define ALGORITMO2WINDOW_H

#include "algoritmo2.h"
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

private slots:
    void on_SelectDirAlg2_pressed();

private:
    Ui::Algoritmo2Window *ui;
    Algoritmo2 algoritmo;
};

#endif // ALGORITMO2WINDOW_H
