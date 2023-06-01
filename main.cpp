#include <iostream>
#include <string>
#include<string.h>
#include "Clientes.h"
using namespace std;
 //salchichones primavera=3

Clientes Cliente[50];
Transacciones baseMov[50];
int ubicC=0;
int ubicT=0;
int i=0;

 void menuTiempo(){
     int opc=1;
     while (opc>0 && opc<4){
         cout<<"¿Por qué periodo de tiempo?"<<endl;
         cout<<"1.Por 6 meses"<<endl;
         cout<<"2.Por un año"<<endl;
         cout<<"3.Total"<<endl;
         cin>>opc;

         //Llamamos a una funcion que evalue segun la opcion ingresada asi no hacemos un switch
     }
 }

 void altaCliente(){
     int num, cinApertura;
     string cinNombre, cinApellido, cinTipo, cinEstado;
     num=ubicC+1;
     cout << "Nombre" << endl;
     cin >> cinNombre;
     cout << "Apellido" << endl;
     cin >> cinApellido;
     cout << "Tipo de cliente (plata, oro, black)" << endl;
     cin >> cinTipo;
     cout << "Momento de apertura de la cuenta" << endl;
     cin >> cinApertura;
     Cliente[ubicC] = Clientes(num, cinNombre, cinApellido, cinTipo, cinApertura, "Activo");
     ubicC++;

 }

 void bajaCliente(){
     int cinNumero;
     cout << "Ingrese el numero de cliente" << endl;
     cin >> cinNumero;
     for (int j=0; j<50; j++){
         if (Cliente[j].getNumero()==cinNumero){
              Cliente[j].baja(cinNumero);
         }
     }
 }

 void extraccion(){
     int cinNumero;
     float cinMonto;
     cout<<"Ingrese el numero de cliente"<<endl;
     cin>>cinNumero;
     cout<<"Ingrese el monto a extraer"<<endl;
     cin>>cinMonto;
     baseMov[ubicT].extraccion();
     ubicT++;
 }

 void deposito(){
     int cinNumero;
     float cinMonto;
     cout<<"Ingrese el numero de cliente"<<endl;
     cin>>cinNumero;
     cout<<"Ingrese el monto a retirar"<<endl;
     cin>>cinMonto;
     baseMov[ubicT].deposito();
     ubicT++;
 }
 void consultaPorNumero(){
     int cinNumero;
     cout << "Ingrese el numero de cliente" << endl;
     cin >> cinNumero;
     for (int j=0; j<50; j++){
         if (Cliente[j].getNumero()==cinNumero){
              Cliente[j].mostrarCliente();
         }
     }
 }

 void consultaPorNumTr(){
     int cinNumero;
     cout << "Ingrese el numero de transaccion: " << endl;
     cin >> cinNumero;
     for(int j=0; j<50; j++){
         if(baseMov[j].getNroTran()==cinNumero){
             baseMov[j].mostrarTransaccion();
         }
     }
 }

 void menuExtra(){
     int op=1;
     int cinNumero;
     while (op>0 && op<5){
         cout<<"Ingrese una opcion"<<endl;
         cout<<"1.Consultar cliente (Por numero)"<<endl;
         cout<<"2.Mostrar todos los clientes"<<endl;
         cout<<"3.Transacciones de cliente (por numero)"<<endl;
         cout<<"4.Informe de extraccion y deposito por cliente (numero)"<<endl;
         cin>>op;
         switch (op) {
             case 1:{

                 break;
             }
             case 2: {

                 break;
             }
             case 3: {


                 break;
             }
             case 4: {

                 break;
             }
         }
     }
 };


int main() {
    int opcion = 1;

    /* Clientes clientePrueba(3, "Bautista", "Juncos", "black", 2020, "ACTIVO");
    cout<<clientePrueba.getNumero()<<endl;
    cout<<clientePrueba.getNombre()<<endl;
    cout<<clientePrueba.getApellido()<<endl;
    cout<<clientePrueba.getTipo()<<endl;
    cout<<clientePrueba.getApertura()<<endl;
    cout<<clientePrueba.getEstado()<<endl; */

    cout<<"Bienvenido a banco UCC"<<endl;
    while (opcion>0 && opcion<6){

        cout<<"Menu:"<<endl;
        cout<<"1.Alta cliente"<<endl;
        cout<<"2.Baja cliente"<<endl;
        cout<<"3.Extraccion de dinero"<<endl;
        cout<<"4.Ingreso de dinero"<<endl;
        cout<<"5.Mas opciones"<<endl;
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
