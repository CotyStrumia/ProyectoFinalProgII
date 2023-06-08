//
// Created by COTYS on 8/6/2023.
//
#include <iostream>
using namespace std;
#ifndef PROYECTOFINAL_TARJETAS_H
#define PROYECTOFINAL_TARJETAS_H


class tarjetas {
private:
    float credito;
public:
    tarjetas();
    tarjetas(float);

    void limiteTarjetas(string);

    void setcredito(float _credito);
    float getcredito();
};


#endif //PROYECTOFINAL_TARJETAS_H
