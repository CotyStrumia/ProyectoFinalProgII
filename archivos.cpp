//
// Created by COTYS on 1/6/2023.
//

#include "archivos.h"
#include <fstream>

archivos::archivos() {
    num_cliente=0;
}

archivos::archivos(int _num) {
    num_cliente=_num;
}

void archivos::setNum_cliente(int _num) {
    num_cliente=_num;
}

int archivos::getNum_cliente() {
    return num_cliente;
}

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