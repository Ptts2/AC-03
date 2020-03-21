#include "algoritmo2window.h"
#include "ui_algoritmo2window.h"

#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QFileInfo>
#include <string>
#include <chrono>

using namespace std;

Algoritmo2Window::Algoritmo2Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Algoritmo2Window)
{
    ui->setupUi(this);
    this->algoritmo = Algoritmo2();
    this->tiempos.push_back(ui->tiempo1Alg2);
    this->tiempos.push_back(ui->tiempo2Alg2);
    this->tiempos.push_back(ui->tiempo3Alg2);
    this->tiempos.push_back(ui->tiempo4Alg2);
    this->tiempos.push_back(ui->tiempo5Alg2);

}

Algoritmo2Window::~Algoritmo2Window()
{
    delete ui;
}


QString Algoritmo2Window::addNumToFilename(QString filename, int num)
{
    QFileInfo fileInfo(filename);

    QString directorio;
    QString extension = fileInfo.completeSuffix();


    if (!extension.isEmpty()) {
        extension = "." + extension;
        directorio = filename.left(filename.size() - extension.size());
    } else {
        directorio = filename;
    }
    return directorio +QString::number(num)+extension;
}


void Algoritmo2Window::on_SelectDirAlg2_pressed()
{

     this->algoritmo.setArchivo(QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QDir::currentPath(), tr("Archivos de imagen (*.png *.jpg)")));

}

void Algoritmo2Window::on_ResetAlg2_pressed()
{
    for(int i = 0;i<5;i++)
    {
        this->tiempos[i]->setText("");
    }
    ui->tiempoMedioAlg2->setText("");

    this->algoritmo.setArchivo(tr("null"));

}

void Algoritmo2Window::on_ExecuteAlg2_pressed()
{

    if(this->algoritmo.getFilename().toStdString() == ("null"))
    {
        QMessageBox errorMessage;
        errorMessage.critical(this,"Error","¡Debes seleccionar una imagen!");
        errorMessage.setFixedSize(500,200);
    }
    else
    {
        QString dir = QFileDialog::getSaveFileName(this, tr("Directorio de guardado de imagenes"), QDir::currentPath(), tr("Archivos de imagen (*.png *.jpg)"));
        QImage imagenBlancoYNegro;
        double suma = 0;

        for(int i = 0; i<5; i++)
        {
            auto inicio = chrono::high_resolution_clock::now();

            imagenBlancoYNegro = algoritmo.executeAlg2();
            imagenBlancoYNegro.save(addNumToFilename(dir,i+1));

            auto fin = chrono::high_resolution_clock::now();

            double duracion = chrono::duration_cast<chrono::milliseconds>(fin - inicio).count();
            suma +=duracion;
            this->tiempos[i]->setText(QString::number(duracion)+"ms");
        }

        ui->tiempoMedioAlg2->setText(QString::number(suma/5.0)+"ms");

        //Mostrar imagen por pantalla
        QMessageBox showImage;
        showImage.setIconPixmap(QPixmap::fromImage(imagenBlancoYNegro));
        showImage.exec();
    }

}
