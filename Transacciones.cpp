//
// Created by COTYS on 24/5/2023.
//

#include "Transacciones.h"

Transacciones::Transacciones() {
    nro_transaccion=0;
    cantidad_total=0;
    cantidad=0;
    tipo=' ';
    dia=0;
    mes=0;
    anio=0;
}

Transacciones::Transacciones(int _nro_transaccion, float _cantidad_total, float _cantidad, char _tipo, int _dia, int _mes, int _anio) {
    nro_transaccion=_nro_transaccion;
    cantidad_total=_cantidad_total;
    cantidad=_cantidad;
    tipo=_tipo;
    dia=_dia;
    mes=_mes;
    anio=_anio;
}

void Transacciones::setNroTran(int _nro_transaccion){
    nro_transaccion=_nro_transaccion;
}

void Transacciones::setCantTotal(float _cantidad_total) {
    cantidad_total=_cantidad_total;
}

void Transacciones::setCant(float _cantidad) {
    cantidad=_cantidad;
}

void Transacciones::setTipo(char _tipo) {
    tipo=_tipo;
}

void Transacciones::setDia(int _dia) {
    dia=_dia;
}

void Transacciones::setMes(int _mes) {
    mes=_mes;
}

void Transacciones::setAnio(int _anio) {
    anio=_anio;
}


int Transacciones::getNroTran() {
    return nro_transaccion;
}

float Transacciones::getCantTotal() {
    return cantidad_total;
}

float Transacciones::getCant() {
    return cantidad;
}

char Transacciones::getTipo() {
    return tipo;
}

int Transacciones::getDia() {
    return dia;
}

int Transacciones::getMes() {
    return mes;
}

int Transacciones::getAnio() {
    return anio;
}

void Transacciones::extraccion() {
    cout<<"SU MONTO ACTUAL ES DE: " << cantidad_total << endl;

    if(cantidad <= cantidad_total && cantidad > 0){
        cantidad_total=cantidad_total - cantidad;
        cout<<"SU MONTO ACTUALIZADO ES DE: "<<cantidad_total<<endl;
    }else {
        cout << "El monto a extraer debe ser positivo y/o no debe superar la cantidad actual en la cuenta" << endl;
    }

}

void Transacciones::deposito() {
    cout << "SU MONTO ACTUAL ES DE: " << cantidad_total << endl;
    if (cantidad > 0){
        cantidad_total = cantidad_total + cantidad;
        cout << "SU MONTO ACTUALIZADO ES DE: " << cantidad_total << endl;
    } else {
        cout << "El monto a depositar debe ser positivo" << endl;
    }
}