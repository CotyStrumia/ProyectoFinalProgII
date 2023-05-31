#include <iostream>
#include <fstream>
#include <string>
#include "Clientes.h"
using namespace std;
 //salchichones primavera=3


Clientes baseClientes[50];
Transacciones baseMov[50];
int ubicC=0;
int ubicT=0;

void leerArchivos(){
    int cantPersonas, cantExtracciones;
    string archivoCliente, archivoExtracciones, fila;

    cout<<"Ingrese el nombre del archivo de clientes"<<endl
    cin>>archivoCliente;
    cout<<"Ingrese la cantidad de clientes que se ingresaran"<<endl;
    cin>>cantPersonas;

    ifstream archivo(archivoCliente);
    if (!archivo){
        cout<<"No se puede abrir el archivo"<<endl;
    }else {
        while (getline (archivo, fila) && ubicC<cantPersonas){
            istringstream iss(fila);
            iss >> baseClientes[ubicC].setNumero() >> baseClientes[ubicC].setNombre() >>baseClientes[ubicC].getApellido()
                >>baseClientes[ubicC].setTipo() >> baseClientes[ubicC].setApertura() >> baseClientes[ubicC].setEstado();
            ubicC++;
        }
    }
    archivo.close();
    //ver como enlazar el archivo con el cliente puntual
    cout<<"Ingrese el nombre del archivo de clientes"<<endl
    cin>>archivoExtracciones;
    cout<<"Ingrese la cantidad de clientes que se ingresaran"<<endl;
    cin>>cantExtracciones;
    ifstream archivo(archivoExtracciones);
    if (!archivo){
        cout<<"No se puede abrir el archivo"<<endl;
    }else {
        while (getline (archivo, fila) && ubicT<cantExtracciones){
            istringstream iss(fila);
            iss >> baseMov[ubicT].setNroTran() >> baseMov[ubicT].setCant() >> baseMov[ubicT].setTipo(), baseMov[ubicT].setDia()
            >> baseMov[ubicT].setMes() >> baseMov[ubicT].setAnio();
            i++;
        }
    }
    archivo.close();
}

 void menuTiempo(){
     int opc=1;
     while (opc>0 && opc<4){
         cout<<"¿Por qué periodo de tiempo?"<<endl;
         cout<<"1.Por 6 meses"<<endl;
         cout<<"2.Por un año"<<endl;
         cout<<"3.Total"<<endl;
         cin>>opc;
         switch (opc) {
             case 1:

                 break;
             case 2:
                 break;
             case 3:
                 break;
         }
     }
 }

 void altaCliente(){
     int cinNumero, cinApertura;
     string cinNombre, cinApellido, cinTipo, cinEstado;
     cout << "Nombre" << endl;
     cin >> cinNombre;
     cout << "Apellido" << endl;
     cin >> cinApellido;
     cout << "Tipo de cliente (plata, oro, black)" << endl;
     cin >> cinTipo;
     cout << "Momento de apertura de la cuenta" << endl;
     cin >> cinApertura;
     Clientes cliente2(0, cinNombre, cinApellido, cinTipo, cinApertura, "Activo");
 }

 void bajaCliente(){
     int cinNumero;
     cout << "Ingrese el numero de cliente" << endl;
     cin >> cinNumero;
     cliente1().baja(cinNumero);
 }

 void extraccion(){
     int cinNumero;
     float cinMonto;
     cout<<"Ingrese el numero de cliente"<<endl;
     cin>>cinNumero;
     cout<<"Ingrese el monto a extraer"<<endl;
     cin>>cinMonto;
     transaccion1().extraccion();
 }
 void deposito(){
     int cinNumero;
     float cinMonto;
     cout<<"Ingrese el numero de cliente"<<endl;
     cin>>cinNumero;
     cout<<"Ingrese el monto a retirar"<<endl;
     cin>>cinMonto;
     transaccion1().deposito();
 }

 void menuExtra(){



     int op=1;
     while (op>0 && op<5){
         cout<<"Ingrese una opcion"<<endl;
         cout<<"1.Consultar cliente (Por numero)"<<endl;
         cout<<"2.Mostrar todos los clientes"<<endl;
         cout<<"3.Transacciones de cliente (por numero)"<<endl;
         cout<<"4.Informe de extraccion y deposito por cliente (numero)"<<endl;
         cin>>op;
         switch (op) {
             case 1:
                 break;
             case 2:
                 break;
             case 3:
                 break;
             case 4:
                 menuTiempo();
                 break;
         }
     }
 };


int main() {
    int opcion = 1;



    cout<<"Bienvenido a banco UCC"<<endl;
    while (opcion>0 && opcion<6){
        cout<<"Menu:"<<endl;
        cout<<"1.Alta cliente"<<endl;
        cout<<"2.Baja cliente"<<endl;
        cout<<"3.Extraccion de dinero"<<endl;
        cout<<"4.Ingreso de dinero"<<endl;
        cout<<"5.Más opciones"<<endl;
        cout<<"6.Salir"<<endl;
        cin>>opcion;
        switch (opcion) {
            case 1:
               altaCliente();
                break;
            case 2:
               bajaCliente();
                break;
            case 3:
               extraccion();
                break;
            case 4:
                deposito();
                break;
            case 5:
              menuExtra();
                break;
        }
    }

}
