//
// Created by COTYS on 1/6/2023.
//
#include <iostream>
#ifndef PROYECTOFINAL_ARCHIVOS_H
#define PROYECTOFINAL_ARCHIVOS_H
using namespace std;

struct movimientos_str {
    int numCliente;
    int numDeTrans;
    int cantidad;
    char tipo;
    int dia;
    int mes;
    int anio;
};
struct movimientos_str movimientos[50];

struct clientes_str{
    int numCliente;
    string nombre;
    string apellido;
    string tipo;
    int anio;
    string estado;
};
struct clientes_str Clientes[50];

class archivos {
public:
    void GenerarArchClientes();
    void GenerarArchTransaccciones();
};


#endif //PROYECTOFINAL_ARCHIVOS_H
