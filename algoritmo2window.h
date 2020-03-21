#ifndef ALGORITMO2WINDOW_H
#define ALGORITMO2WINDOW_H

#include "algoritmo2.h"
#include <QDialog>
#include <QVector>

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

    void on_ResetAlg2_pressed();

    void on_ExecuteAlg2_pressed();



private:
    Ui::Algoritmo2Window *ui;
    Algoritmo2 algoritmo;
    std::vector<double> tiempos;
    QString addNumToFilename(QString filename, int num);

};

#endif // ALGORITMO2WINDOW_H
