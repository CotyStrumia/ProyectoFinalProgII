//
// Created by COTYS on 1/6/2023.
//

#include "archivos.h"
#include <iostream>
#include <fstream>
using namespace std;


void archivos::GenerarArchClientes() {
    ofstream archivo;      //Declaro el archivo
    archivo.open("Clientes.txt");     //Abro el archivo y le doy nombre



}

void archivos::GenerarArchTransaccciones() {
    ofstream archivo;
    archivo.open("Transacciones.txt");
    if(archivo.is_open()){

    }
    
}