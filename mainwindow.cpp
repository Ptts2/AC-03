#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoritmo1window.h"
#include "algoritmo2window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_botonAlgoritmo1_pressed()
{
    Algoritmo1Window algoritmo1(this);
    algoritmo1.setModal(true);
    algoritmo1.exec();
}


void MainWindow::on_botonAlgoritmo2_pressed()
{
    Algoritmo2Window algoritmo2(this);
    algoritmo2.setModal(true);
    algoritmo2.exec();
}
