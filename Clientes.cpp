#include "Clientes.h"

Clientes::Clientes(){
        numero=0;
        nombre=" ";
        apellido=" ";
        tipo=" ";
        apertura=0;
        estado=" ";
}

Clientes::Clientes(int _numero, string _nombre, string _apellido, string _tipo, int _apertura, string _estado) {
    numero = _numero;
    nombre = _nombre;
    apellido = _apellido;
    tipo = _tipo;
    apertura = _apertura;
    estado = _estado;
}

void Clientes::setNumero(int _numero) {
    numero=_numero;
}
int Clientes::getNumero(){
    return numero;
}


void Clientes::setNombre(string _nombre) {
    nombre=_nombre;
}
string Clientes::getNombre(){
    return nombre;
}


void Clientes::setApellido(string _apellido) {
    apellido=_apellido;
}
string Clientes::getApellido(){
    return apellido;
}


void Clientes::setTipo(string _tipo) {
    tipo=_tipo;
}
string Clientes::getTipo() {
    return tipo;
}


void Clientes::setApertura(int _apertura) {
    apertura=_apertura;
}
int Clientes::getApertura() {
    return apertura;
}


void Clientes::setEstado(string _estado) {
    estado=_estado;
}
string Clientes::getEstado(){
    return estado;
}

void Clientes::baja(int cinnumero) {
    //SE VE DESPUES LACONCHADELALORA
    setEstado("BAJA");
    cout<<"Su estado es de: "<<getEstado() << endl;
}
