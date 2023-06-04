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
    float saldo;
public:

    Transacciones Transacciones[50];

    Clientes();
    Clientes(int, string, string, string, int, string, float);

    void setNumero(int _numero);
    void setNombre(string _nombre);
    void setApellido (string _apellido);
    void setTipo (string _tipo);
    void setApertura (int _apertura);
    void setEstado (string _estado);
    void setSaldo(float _saldo);

    int getNumero();
    string getNombre();
    string getApellido();
    string getTipo();
    int getApertura();
    string getEstado();
    float getSaldo();

    void baja(int);
    void extraccion(int num, float monto);
    void deposito(float);
    void mostrarCliente();

};


#endif //PROYECTOFINAl_CLIENTES_H
