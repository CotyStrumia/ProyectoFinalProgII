#include "Clientes.h"

Clientes::Clientes(){
        numero=0;
        nombre="";
        apellido="";
        tipo=" ";
        apertura=0;
        estado=" ";
        saldo=0;
}

Clientes::Clientes(int _numero, string _nombre, string _apellido, string _tipo, int _apertura, string _estado, float _saldo) {
    numero = _numero;
    nombre = _nombre;
    apellido = _apellido;
    tipo = _tipo;
    apertura = _apertura;
    estado = _estado;
    saldo= _saldo;
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

void Clientes::setSaldo(float _saldo) {
    saldo=_saldo;
}
float Clientes::getSaldo() {
    return saldo;
}

void Clientes::baja(int cinnumero) {
    setEstado("BAJA");
    cout<<"Su estado es de: "<<getEstado() << endl;
}

void Clientes::mostrarCliente() {
    cout << "NUMERO DE CLIENTE: " << numero << endl;
    cout << "NOMBRE: " << nombre << endl;
    cout << "APELLIDO: " << apellido << endl;
    cout << "TIPO: " << tipo << endl;
    cout << "ANIO DE APERTURA: " << apertura << endl;
    cout << "ESTADO: " << estado << endl;
}

void Clientes::extraccion(int num, float monto) {


    //Transacciones[i].setTipo('E');
    //cout << "SU MONTO ACTUAL ES DE: " << Transacciones[i].getCant() << endl;


    if(monto <= getSaldo() && monto>0){

    }

    /* if (Transacciones[i].getCant() <= saldo && monto > 0) {

        saldo = saldo - Transacciones[i].getCant();

        cout << "SU MONTO ACTUALIZADO ES DE: " << saldo << endl;

        Transacciones[i] = Transacciones(i, saldo, monto, 'E', dia, mes, anio);

    } else {

        cout << "El monto a extraer debe ser positivo y/o no debe superar la cantidad actual en la cuenta"
             << endl;

    } */
}



void Clientes::deposito(float monto) {

    int dia, mes, anio;
    cout << "Ingrese la fecha actual: " << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Anio: " << endl;
    cin >> anio;

    //Transacciones[i].setTipo('D');
    cout<<"SU MONTO ACTUAL ES DE: " << getSaldo() << endl;

    if(monto <= getSaldo() && monto > 0){
        setSaldo(getSaldo()+monto);
        cout<<"SU MONTO ACTUALIZADO ES DE: "<<getSaldo()<<endl;
    } else {
        cout << "El monto a extraer debe ser positivo y/o no debe superar la cantidad actual en la cuenta" << endl;
    }
}
