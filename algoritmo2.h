#ifndef ALGORITMO2_H
#define ALGORITMO2_H
#include <QString>
#include <vector>

class Algoritmo2
{
public:
    Algoritmo2();
    ~Algoritmo2();
    void setArchivo(QString archivo);

    void resetTiempos();
    std::vector<double> getTiempos();


private:
    QString archivo;
    std::vector<double> tiempos;
};

#endif // ALGORITMO2_H
