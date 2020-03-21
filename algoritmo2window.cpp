#include "algoritmo2window.h"
#include "ui_algoritmo2window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QFileInfo>

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
    ui->tiempo1Alg2->setText("");
    ui->tiempo2Alg2->setText("");
    ui->tiempo3Alg2->setText("");
    ui->tiempo4Alg2->setText("");
    ui->tiempo5Alg2->setText("");
    ui->tiempoMedioAlg2->setText("");

    this->algoritmo.setArchivo(tr("null"));
    this->tiempos.clear();
}

void Algoritmo2Window::on_ExecuteAlg2_pressed()
{
    QString dir = QFileDialog::getSaveFileName(this, tr("Directorio de guardado de imagenes"), QDir::currentPath(), tr("Archivos de imagen (*.png *.jpg)"));
    QImage imagenBlancoYNegro;

    for(int i = 0; i<5; i++)
    {
        imagenBlancoYNegro = algoritmo.executeAlg2();
        imagenBlancoYNegro.save(addNumToFilename(dir,i+1));
    }

    //Mostrar imagen por pantalla
    QMessageBox showImage;
    showImage.setIconPixmap(QPixmap::fromImage(imagenBlancoYNegro));
    showImage.exec();


}
