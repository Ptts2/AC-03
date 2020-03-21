#include "algoritmo2.h"

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
