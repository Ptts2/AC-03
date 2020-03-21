#include "algoritmo2.h"
//#include <QImage>

Algoritmo2::Algoritmo2()
{
    this->archivo = QString("null");
}

Algoritmo2::~Algoritmo2()
{
}

void Algoritmo2::setArchivo(QString archivo)
{

    this->archivo = archivo;

}

void Algoritmo2::resetTiempos()
{
    this->tiempos.clear();
}

QImage Algoritmo2::executeAlg2()
{
    QImage imagen = QImage(this->archivo);
    return imagen.convertToFormat(QImage::Format_Grayscale16);
}
