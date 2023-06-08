//
// Created by COTYS on 8/6/2023.
//

#include "tarjetas.h"

tarjetas::tarjetas() {
    credito=0;
}

tarjetas::tarjetas(float _credito){
    credito=_credito;
}

void tarjetas::setcredito(float _credito) {
    credito=_credito;
}

float tarjetas::getcredito() {
    return credito;
}

void tarjetas::limiteTarjetas(string tipo) {
    if (tipo=="oro"){
        setcredito(50000);
        cout<<"Usted tiene acceso a una tarjeta de credito con un limite de: "<<getcredito()<<endl;
    }else if(tipo=="black"){
        setcredito(250000);
        cout<<"Usted tiene acceso a una tarjeta de credito con un limite de: "<<getcredito()<<endl;
    }else{
        cout<<"Lo siento, usted no tiene acceso a una tarjeta de credito"<<endl;
    }
}