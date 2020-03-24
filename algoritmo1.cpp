#include "algoritmo1.h"

#include <vector>

Algoritmo1::Algoritmo1()
{

}

Algoritmo1::~Algoritmo1()
{

}

int Algoritmo1::fibonacci(int numero)
{
    int suma = 0;
    std::vector<int> medias;
    medias.clear();
    medias.push_back(0);
    for(int i=1; i<=numero; i++){
        suma = medias[i-1]+i;
        medias.push_back(suma);
    }
    return suma;
}
