#include "algoritmo2window.h"
#include "ui_algoritmo2window.h"

Algoritmo2Window::Algoritmo2Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Algoritmo2Window)
{
    ui->setupUi(this);
}

Algoritmo2Window::~Algoritmo2Window()
{
    delete ui;
}
