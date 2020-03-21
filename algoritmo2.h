#ifndef ALGORITMO2_H
#define ALGORITMO2_H
#include <QString>
#include <QImage>

class Algoritmo2
{
public:
    Algoritmo2();
    ~Algoritmo2();
    void setArchivo(QString archivo);
    QImage executeAlg2();

private:
    QString archivo;

};

#endif // ALGORITMO2_H
