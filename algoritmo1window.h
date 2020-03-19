#ifndef ALGORITMO1WINDOW_H
#define ALGORITMO1WINDOW_H

#include <QDialog>

namespace Ui {
class Algoritmo1Window;
}

class Algoritmo1Window : public QDialog
{
    Q_OBJECT

public:
    explicit Algoritmo1Window(QWidget *parent = nullptr);
    ~Algoritmo1Window();

private:
    Ui::Algoritmo1Window *ui;
};

#endif // ALGORITMO1WINDOW_H
