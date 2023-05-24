#include <iostream>
#include "Clientes.h"
using namespace std;
 //salchichones primavera=3

int main() {
    int opcion = 1;
    int cinNumero, cinApertura;
    string cinNombre, cinApellido, cinTipo, cinEstado;
    float cinMonto;
    Clientes cliente1();
    Transacciones transaccion1();

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
            case 1: {
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
                break;
            case 2: {
                cout << "Ingrese el numero de cliente" << endl;
                cin >> cinNumero;
                cliente1().baja(cinNumero);
            }
                break;
            case 3:
                cout<<"Ingrese el numero de cliente"<<endl;
                cin>>cinNumero;
                cout<<"Ingrese el monto a extraer"<<endl;
                cin>>cinMonto;
                transaccion1().extraccion();
                break;
            case 4:
                cout<<"Ingrese el numero de cliente"<<endl;
                cin>>cinNumero;
                cout<<"Ingrese el monto a retirar"<<endl;
                cin>>cinMonto;
                transaccion1().deposito();
                break;
            case 5:
                //agregar una funcion con el resto del menu
                break;
        }
    }

}
