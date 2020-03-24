#include "algoritmo1window.h"
#include "ui_algoritmo1window.h"
#include "algoritmo1.h"

#include <iostream>
#include <QMessageBox>
#include <chrono>
#include <QFile>
#include <QTextStream>


using namespace std;

Algoritmo1Window::Algoritmo1Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Algoritmo1Window)
{
    ui->setupUi(this);
    this->tiempos.push_back(ui->tiempo1Alg1);
    this->tiempos.push_back(ui->tiempo2Alg1);
    this->tiempos.push_back(ui->tiempo3Alg1);
    this->tiempos.push_back(ui->tiempo4Alg1);
    this->tiempos.push_back(ui->tiempo5Alg1);

    this->archivoDir = "./fibonacci.txt";
}

Algoritmo1Window::~Algoritmo1Window()
{
    delete ui;

}

vector<int> Algoritmo1Window::readFibonacci()
{
    vector<int> ejemplos;
    vector<QString> lineas;
    QFile archivo(this->archivoDir);
    if(archivo.open(QIODevice::ReadOnly))
    {
        QTextStream entrada(&archivo);
        while(!entrada.atEnd())
        {
            lineas.push_back(entrada.readLine());
        }
        for(int i=0;i<(int) lineas.size();i++)
        {
            auto palabras = lineas[i].split(" ");
            for(int j=0;j<(int) palabras.size();j++)
            {
                ejemplos.push_back(palabras[j].toInt());
            }
        }
    }else
    {
        ejemplos.push_back(-1);
    }
    return ejemplos;
}

void Algoritmo1Window::on_ExecuteAlg1_clicked()
{
    vector<int> numeros = readFibonacci();
    double mediaTiempo = 0;
    bool correcto = true;
    int k = 0;
    while(correcto && k<(int) numeros.size())
    {
        if(numeros[k] < 0)
        {
            QMessageBox errorMessage;
            errorMessage.critical(this,"Error","¡Debes introducir un archivo, con numeros validos!");
            errorMessage.setFixedSize(500,200);
            correcto = false;
        }
        k++;
    }

    if(correcto)
    {
        for(int i=0; i<5; i++)
        {
            auto inicio = chrono::high_resolution_clock::now();
            for(int j=0;j<(int) numeros.size();j++)
            {
                algoritmo.Algoritmo1::fibonacci(numeros[j]);
            }
            auto fin = chrono::high_resolution_clock::now();

            double duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
            mediaTiempo +=duracion;
            tiempos[i]->setText(QString::number(duracion)+"μs");

        }
        ui->tiempoMedioAlg1->setText(QString::number(mediaTiempo/5)+"μs");
    }
}

void Algoritmo1Window::on_ResetAlg1_clicked()
{
    ui->tiempo1Alg1->setText("");
    ui->tiempo2Alg1->setText("");
    ui->tiempo3Alg1->setText("");
    ui->tiempo4Alg1->setText("");
    ui->tiempo5Alg1->setText("");
    ui->tiempoMedioAlg1->setText("");
}
