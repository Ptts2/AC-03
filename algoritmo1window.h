#ifndef ALGORITMO1WINDOW_H
#define ALGORITMO1WINDOW_H
#include "algoritmo1.h"
#include <QDialog>
#include <QLabel>
#include <vector>


namespace Ui {
class Algoritmo1Window;
}

class Algoritmo1Window : public QDialog
{
    Q_OBJECT

public:
    explicit Algoritmo1Window(QWidget *parent = nullptr);
    ~Algoritmo1Window();

private slots:
    void on_ExecuteAlg1_clicked();

    void on_ResetAlg1_clicked();

private:
    Ui::Algoritmo1Window *ui;
    Algoritmo1 algoritmo;
    std::vector<QLabel*> tiempos;

    std::vector<int> readFibonacci();
    QString archivoDir;
};

#endif // ALGORITMO1WINDOW_H
