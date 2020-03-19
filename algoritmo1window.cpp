#include "algoritmo1window.h"
#include "ui_algoritmo1window.h"

Algoritmo1Window::Algoritmo1Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Algoritmo1Window)
{
    ui->setupUi(this);
}

Algoritmo1Window::~Algoritmo1Window()
{
    delete ui;
}
