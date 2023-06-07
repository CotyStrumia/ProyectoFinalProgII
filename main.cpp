#include <iostream>
#include <string>
#include "Clientes.h"
#include "archivos.h"
using namespace std;
 //salchichones primavera=3

Clientes Cliente[50];
int ubicC=0;
int nro_T=0;


bool verificarFecha(int cDia, int cMes, int cAnio) {
    if (cMes >0 && cMes < 13) {
        if (cMes == 1 || cMes == 3 || cMes == 5 || cMes == 7 || cMes == 8 || cMes == 10 || cMes == 12) {
            if (cDia < 0 || cDia > 31) {
                return false;
            }
        }else if (cMes == 4 || cMes == 6, cMes == 9, cMes == 11) {
            if (cDia < 0 || cDia > 30) {
                return false;
            }
        }else if (cMes == 2) {
            if (cDia < 0 || cDia > 28) {
                return false;
            }
        }
       if(cAnio<0 || cAnio>2023){
            return false;
        }
        return true;
    } else if (cMes < 0 || cMes > 12) {
        return false;
    }
}

bool verificadorAlta(int cAnio){
    if (cAnio<0 || cAnio>2023){
        return false;
    }else{
        return true;
    }
}


 void menuTiempo() {
     int opc = 1;
     while (opc > 0 && opc < 4) {
         cout << "¿Por qué periodo de tiempo?" << endl;
         cout << "1.Por 6 meses" << endl;
         cout << "2.Por un año" << endl;
         cout << "3.Total" << endl;
         cin >> opc;

         switch (opc) {
             case 1:
                 /*trSeisMeses();*/
                 break;

             case 2:
                 /*trAnio();*/
                 break;

             case 3:
                 /*trTotal();*/

                 break;

         }

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

     if(cinApertura>=2020 && (cinTipo=="black" || cinTipo=="BLACK" || cinTipo=="Black")){
         cout<<"Los clientes con una antiguedad menor a 3 años no pueden ser de tipo black"<<endl;
     }else{
         Cliente[ubicC] = Clientes(num, cinNombre, cinApellido, cinTipo, cinApertura, "Activo", 0);
         cout<<"Se le ha dado alta al cliente: "<<Cliente[ubicC].getNombre()<<" "<<Cliente[ubicC].getApellido()<<", numero "<<num<<" exitosamente"<<endl;
         ubicC++;

         archivos(num);  //para hacer el txt

     }

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

 void extraccion(){ //LISTO BR0
     int cinNumero, dia, mes, anio, i=0;
     float cinMonto;

     cout << "Ingrese el dia: " << endl;
     cin >> dia;
     cout << "Ingrese el mes: " << endl;
     cin >> mes;
     cout << "Ingrese el anio: " << endl;
     cin >> anio;

     cout<<"Ingrese su numero de cliente"<<endl;
     cin>>cinNumero;

    if(verificarFecha(dia, mes, anio)==true){

        for (i = 0; i < 50; i++) {
            if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "Activo") {

                cout<<"Ingrese el monto a extraer"<<endl;
                cin>>cinMonto;

                if(cinMonto<=Cliente[i].getSaldo() && cinMonto>0) {

                    Cliente[i].setSaldo(Cliente[i].getSaldo() - cinMonto);

                    cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                    Cliente[i].Transacciones[nro_T] = Transacciones(nro_T+1, Cliente[i].getSaldo(), cinMonto, 'E', dia, mes, anio);

                    Cliente[i].Transacciones[nro_T].mostrarTransaccion();
                    i=49;
                    nro_T++;

                }else{
                    cout<<"ERROR: El monto ingresado es mayor al saldo o es negativo"<<endl;

                    i=49;

                }

            } else if (i == 49 && Cliente[i].getNumero() != cinNumero) {
                cout << "Cliente no encontrado"<<endl;

            }
        }
    } else{
        cout<<"La fecha ingresada es invalida"<<endl;
    }

 }


 void deposito(){
     int cinNumero, dia, mes, anio, i=0;
     float cinMonto;

     cout << "Ingrese el dia: " << endl;
     cin >> dia;
     cout << "Ingrese el mes: " << endl;
     cin >> mes;
     cout << "Ingrese el anio: " << endl;
     cin >> anio;

     cout<<"Ingrese su numero de cliente"<<endl;
     cin>>cinNumero;

     if(verificarFecha(dia, mes, anio)==true) {
         for (i = 0; i < 50; i++) {
             if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "Activo") {

                 cout << "Ingrese el monto a depositar" << endl;
                 cin >> cinMonto;

                 if (cinMonto > 0) {

                     Cliente[i].setSaldo(Cliente[i].getSaldo() + cinMonto);

                     cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                     Cliente[i].Transacciones[nro_T] = Transacciones(nro_T + 1, Cliente[i].getSaldo(), cinMonto, 'D',
                                                                     dia, mes, anio);

                     Cliente[i].Transacciones[nro_T].mostrarTransaccion();
                     i = 49;
                     nro_T++;

                 } else {
                     cout << "ERROR: El monto ingresado es negativo" << endl;
                     i = 49;

                 }

             } else if (i == 49 && Cliente[i].getNumero() != cinNumero) {
                 cout << "Cliente no encontrado" << endl;

             }
         }
     }

 }

 void consultaPorNumeroCli(){
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
     cout << "Ingrese el numero de cliente: " << endl;
     cin >> cinNumero;

         if (Cliente[cinNumero-1].getNumero()==cinNumero){
             for (int i = 0; i < 50; ++i) {
                 cout<<Cliente[cinNumero-1].Transacciones[cinNumero-1].getNroTran()<<" | "<<Cliente[cinNumero-1].Transacciones[i].getCant()<<" | "<<Cliente[cinNumero-1].Transacciones[i].getTipo()<<" | "<<Cliente[cinNumero-1].Transacciones[i].getDia()<<" | "<<Cliente[cinNumero-1].Transacciones[i].getMes()<<" | "<<Cliente[cinNumero-1].Transacciones[i].getAnio()<<endl;
             }
         }
 }

 void mostrarClientes(){
     for(int i=0; i<50; i++){
         if(Cliente[i].getNumero()!=0){
             cout<<Cliente[i].getNumero()<<" | "<<Cliente[i].getNombre()<<" | "<<Cliente[i].getApellido()<<" | "<<Cliente[i].getTipo()<<" | "<<Cliente[i].getApertura()<<" | "<<Cliente[i].getEstado()<<endl;
         }
     }
 }

 void menuExtra(){
     int op=1;
     while (op>0 && op<5){
         cout<<"Ingrese una opcion: "<<endl;
         cout<<"1.Consultar cliente (por numero)"<<endl;
         cout<<"2.Mostrar todos los clientes"<<endl;
         cout<<"3.Transacciones de cliente (por numero)"<<endl;
         cout<<"4.Informe de transacciones"<<endl;
         cin>>op;
         switch (op) {
             case 1:
                 consultaPorNumeroCli();
                 break;

             case 2: {
                 mostrarClientes();
                 break;
             }
             case 3: {
                 consultaPorNumTr();
                 break;
             }
             case 4: {
                 menuTiempo();
                 break;
             }
         }
     }
 }


int main() {
    int opcion = 1;

    Cliente[ubicC] = Clientes(ubicC+1, "Bautista", "Juncos", "black", 2020, "Activo", 100);
    cout<<Cliente[ubicC].getNumero()<<endl;
    cout<<Cliente[ubicC].getNombre()<<endl;
    cout<<Cliente[ubicC].getApellido()<<endl;
    cout<<Cliente[ubicC].getTipo()<<endl;
    cout<<Cliente[ubicC].getApertura()<<endl;
    cout<<Cliente[ubicC].getEstado()<<endl;

    cout<<"Bienvenido a banco UCC"<<endl;
    while (opcion>0 && opcion<6){

        cout<<"Menu:"<<endl;
        cout<<"1.Alta cliente"<<endl;               //Listo
        cout<<"2.Baja cliente"<<endl;               //Listo
        cout<<"3.Extraccion de dinero"<<endl;       //Listo
        cout<<"4.Deposito de dinero"<<endl;         //Listo
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
