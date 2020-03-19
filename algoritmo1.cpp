#include "algoritmo1.h"
#include "ui_algoritmo1.h"

Algoritmo1::Algoritmo1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Algoritmo1)
{
    ui->setupUi(this);
}

Algoritmo1::~Algoritmo1()
{
    delete ui;
}
