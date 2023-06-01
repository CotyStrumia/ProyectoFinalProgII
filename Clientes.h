#include <iostream>
#include "Transacciones.h"
#ifndef PROYECTOFINAL_CLIENTES_H
#define PROYECTOFINAL_CLIENTES_H
using namespace std;

class Clientes {
protected:
    int numero;
    string nombre;
    string apellido;
    string tipo;
    int apertura;
    string estado;

public:
    Transacciones Transacciones;

    Clientes();
    Clientes(int, string, string, string, int, string);

    void setNumero(int _numero);
    void setNombre(string _nombre);
    void setApellido (string _apellido);
    void setTipo (string _tipo);
    void setApertura (int _apertura);
    void setEstado (string _estado);

    int getNumero();
    string getNombre();
    string getApellido();
    string getTipo();
    int getApertura();
    string getEstado();

    void baja(int);

    void mostrarCliente();

};


#endif //PROYECTOFINAl_CLIENTES_H
