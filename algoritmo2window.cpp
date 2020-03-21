#include "algoritmo2window.h"
#include "ui_algoritmo2window.h"
#include <QFileDialog>

Algoritmo2Window::Algoritmo2Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Algoritmo2Window)
{
    ui->setupUi(this);
    this->algoritmo = Algoritmo2();
}

Algoritmo2Window::~Algoritmo2Window()
{
    delete ui;
}

void Algoritmo2Window::on_SelectDirAlg2_pressed()
{

     this->algoritmo.setArchivo(QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QDir::currentPath(), tr("Archivos de imagen (*.png *.jpg)")));

}

void Algoritmo2Window::on_ResetAlg2_pressed()
{
    ui->tiempo1Alg2->setText("");
    ui->tiempo2Alg2->setText("");
    ui->tiempo3Alg2->setText("");
    ui->tiempo4Alg2->setText("");
    ui->tiempo5Alg2->setText("");
    ui->tiempoMedioAlg2->setText("");

    this->algoritmo.setArchivo(tr("null"));
    this->algoritmo.resetTiempos();
}
