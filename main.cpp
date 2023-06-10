#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

#include "Clientes.h"

using namespace std;

Clientes Cliente[50];          //Instanciacion por defecto de nuestra base de datos de los clientes
int ubicC = 0;                 //Declaracion de variables globales en constante uso
int nro_T = 0;
ifstream archivoClientes;  //Declaramos los ficheros (archivos txt) como globales
ifstream archivoMovimientos;

bool verificarFecha(int cDia, int cMes, int cAnio) {
    if (cMes > 0 && cMes < 13) {
        if (cDia > 0 && cDia < 32) {
            if (cMes == 4 || cMes == 6, cMes == 9, cMes == 11) {
                if (cDia > 30) {
                    return false;
                }
            } else if (cMes == 2) {
                if (cDia > 29) {
                    return false;
                }
                if (cAnio < 2000 || cAnio > 2023) {
                    return false;
                }

            }
        }
        return true;
    }else if (cMes < 0 || cMes > 12) {
        return false;
    }
}

bool verificadorAlta(int cAnio) {
    if (cAnio < 2000 || cAnio > 2023) {
        return false;
    } else {
        return true;
    }
}

void trSeisMeses() {
    for (int i = 0; i < 50; i++) {
        if (Cliente[i].Transacciones[i].getAnio() == 2023 && Cliente[i].Transacciones[i].getMes() > 0 &&
            Cliente[i].Transacciones[i].getMes() < 7) {
            Cliente[i].Transacciones[i].mostrarTransaccion();
        }
    }

}

void trAnio() {
    for (int i = 0; i < 50; i++) {
        if (Cliente[i].Transacciones[i].getAnio() == 2023 && Cliente[i].Transacciones[i].getAnio() == 2022 &&
            Cliente[i].Transacciones[i].getMes() > 0 && Cliente[i].Transacciones[i].getMes() < 7) {
            Cliente[i].Transacciones[i].mostrarTransaccion();
        }
    }
}

void trTotal() {
    for (int i = 0; i < 50; i++) {
        Cliente[i].Transacciones[i].mostrarTransaccion();
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
                trSeisMeses();
                break;

            case 2:
                trAnio();
                break;

            case 3:
                trTotal();

                break;

        }
    }
}

void generarClientesTxt(int num) {
//    if (num > 0) {
//        archivoClientes.open("Clientes.txt", ios::app);  //Abrimos el fichero en modo "añadir"
//        archivoClientes <<Cliente[num-1].getNumero() << ", "<<Cliente[num-1].getNombre()<<", "<<Cliente[num-1].getApellido()<<", "<<Cliente[num-1].getTipo()<<", "<<Cliente[num-1].getApertura()<<", "<<Cliente[num-1].getEstado()<<endl;
//        archivoClientes.close();
//        ifstream fileloaded;
//    }
}

void altaCliente() {
    int num, cinApertura;
    string cinNombre, cinApellido, cinTipo, cinEstado;
    num = ubicC + 1;
    cout << "Nombre" << endl;
    cin >> cinNombre;
    cout << "Apellido" << endl;
    cin >> cinApellido;

    cout << "Tipo de cliente (plata, oro, black)" << endl;
    cin >> cinTipo;

    cout << "Momento de apertura de la cuenta" << endl;
    cin >> cinApertura;


    if (verificadorAlta(cinApertura)) {

        if (cinApertura >= 2020 && (cinTipo == "black" || cinTipo == "BLACK" || cinTipo == "Black")) {
            cout << "Los clientes con una antiguedad menor a 3 anios no pueden ser de tipo black" << endl;

        } else {

            Cliente[ubicC].tarjetas.limiteTarjetas(cinTipo);

            Cliente[ubicC] = Clientes(num, cinNombre, cinApellido, cinTipo, cinApertura, "ACTIVO", 0);

            generarClientesTxt(num);

            cout << "Se le ha dado alta al cliente: " << Cliente[ubicC].getNombre() << " "
                 << Cliente[ubicC].getApellido() << endl;
            cout << "Su numero de cliente asignado es: " << num << endl;

            ubicC++;
        }
    } else {
        cout << "Anio invalido" << endl;
    }
}

void bajaCliente() {
    int cinNumero;
    cout << "Ingrese el numero de cliente" << endl;
    cin >> cinNumero;

    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {

            Cliente[j].baja(cinNumero);

            remove("Clientes.txt");
//            archivoClientes.open("Clientes.txt");
//            archivoClientes << "--------------LISTADO DE CLIENTES--------------" << endl;
//            archivoClientes.close();
//            archivoClientes.open("Clientes.txt", ios::app);

            for(int i=0; i<50; i++){
                if(Cliente[i].getNumero()!=0){
//                    archivoClientes <<Cliente[i].getNumero() << " "<<Cliente[i].getNombre()<<" "<<Cliente[i].getApellido()<<" "<<Cliente[i].getTipo()<<" "<<Cliente[i].getApertura()<<endl;
                }
            }

            archivoClientes.close();

            ifstream fileloaded;

        }
    }
}

void extraccion() { //LISTO BR0
    int cinNumero, dia, mes, anio, i = 0;
    float cinMonto;

    cout << "Ingrese el dia: " << endl;
    cin >> dia;
    cout << "Ingrese el mes: " << endl;
    cin >> mes;
    cout << "Ingrese el anio: " << endl;
    cin >> anio;

    if (verificarFecha(dia, mes, anio)) {

        cout << "Ingrese su numero de cliente" << endl;
        cin >> cinNumero;

        for (i = 0; i < 50; i++) {
            if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "ACTIVO") {

                cout << "Ingrese el monto a extraer" << endl;
                cin >> cinMonto;

                if (cinMonto <= Cliente[i].getSaldo() && cinMonto > 0) {

                    Cliente[i].setSaldo(Cliente[i].getSaldo() - cinMonto);

                    cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                    Cliente[i].Transacciones[nro_T] = Transacciones(nro_T + 1, Cliente[i].getSaldo(), cinMonto, 'E',
                                                                    dia, mes, anio);

                    Cliente[i].Transacciones[nro_T].mostrarTransaccion();

                    if (archivoMovimientos.is_open()) {

//                        archivoMovimientos << Cliente[i].getNumero() <<", "<<Cliente[i].Transacciones[nro_T].getNroTran()<<", "<< Cliente[i].Transacciones[nro_T].getCant()<<", "<<Cliente[i].Transacciones[nro_T].getTipo()<<", "<<Cliente[i].Transacciones[nro_T].getDia()<<", "<<Cliente[i].Transacciones[nro_T].getMes()<<", "<<Cliente[i].Transacciones[nro_T].getAnio()<<endl;
                        ifstream fileloaded;

                    } else {
                        archivoMovimientos.open("Movimientos.txt");
//                        archivoMovimientos << Cliente[i].getNumero() <<", "<<Cliente[i].Transacciones[nro_T].getNroTran()<<", "<< Cliente[i].Transacciones[nro_T].getCant()<<", "<<Cliente[i].Transacciones[nro_T].getTipo()<<", "<<Cliente[i].Transacciones[nro_T].getDia()<<", "<<Cliente[i].Transacciones[nro_T].getMes()<<", "<<Cliente[i].Transacciones[nro_T].getAnio()<<endl;
                        ifstream fileloaded;
                    }

                    i = 49;
                    nro_T++;

                } else {
                    cout << "ERROR: El monto ingresado es mayor al saldo o es negativo" << endl;

                    i = 49;

                }

            } else if (i == 49 && Cliente[i].getNumero() != cinNumero) {
                cout << "Cliente no encontrado" << endl;

            }
        }

    } else {
        cout << "La fecha ingresada es invalida" << endl;
    }

}

void deposito() {
    int cinNumero, dia, mes, anio, i = 0;
    float cinMonto;

    cout << "Ingrese el dia: " << endl;
    cin >> dia;
    cout << "Ingrese el mes: " << endl;
    cin >> mes;
    cout << "Ingrese el anio: " << endl;
    cin >> anio;



    if (verificarFecha(dia, mes, anio)) {
        cout << "Ingrese su numero de cliente" << endl;
        cin >> cinNumero;
        for (i = 0; i < 50; i++) {
            if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "ACTIVO") {

                cout << "Ingrese el monto a depositar" << endl;
                cin >> cinMonto;

                if (cinMonto > 0) {

                    Cliente[i].setSaldo(Cliente[i].getSaldo() + cinMonto);

                    cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                    Cliente[i].Transacciones[nro_T] = Transacciones(nro_T + 1, Cliente[i].getSaldo(), cinMonto, 'D',
                                                                    dia, mes, anio);

                    if (archivoMovimientos.is_open()) {


//                        archivoMovimientos << Cliente[i].getNumero() <<", "<<Cliente[i].Transacciones[nro_T].getNroTran()<<", "<< Cliente[i].Transacciones[nro_T].getCant()<<", "<<Cliente[i].Transacciones[nro_T].getTipo()<<", "<<Cliente[i].Transacciones[nro_T].getDia()<<", "<<Cliente[i].Transacciones[nro_T].getMes()<<", "<<Cliente[i].Transacciones[nro_T].getAnio()<<endl;
                        ifstream fileloaded;

                    } else {
                        archivoMovimientos.open("Movimientos.txt");
//                        archivoMovimientos << Cliente[i].getNumero() <<", "<<Cliente[i].Transacciones[nro_T].getNroTran()<<", "<< Cliente[i].Transacciones[nro_T].getCant()<<", "<<Cliente[i].Transacciones[nro_T].getTipo()<<", "<<Cliente[i].Transacciones[nro_T].getDia()<<", "<<Cliente[i].Transacciones[nro_T].getMes()<<", "<<Cliente[i].Transacciones[nro_T].getAnio()<<endl;
                        ifstream fileloaded;
                    }

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
    } else {
        cout << "La fecha ingresada es invalida" << endl;
    }

}

void consultaPorNumeroCli() {
    int cinNumero;
    cout << "Ingrese el numero de cliente" << endl;
    cin >> cinNumero;
    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {
            Cliente[j].mostrarCliente();
        } else if (j == 49 && Cliente[j].getNumero() != cinNumero) {
            cout << "Cliente no encontrado" << endl;
        }
    }
}

void consultaTrPorNumCliente() {
    int cinNumero;
    cout << "Ingrese el numero de cliente: " << endl;
    cin >> cinNumero;

    if (Cliente[cinNumero - 1].getNumero() == cinNumero) {
        for (int i = 0; i < 50; ++i) {
            cout << Cliente[cinNumero - 1].Transacciones[cinNumero - 1].getNroTran() << " | "
                 << Cliente[cinNumero - 1].Transacciones[i].getCant() << " | "
                 << Cliente[cinNumero - 1].Transacciones[i].getTipo() << " | "
                 << Cliente[cinNumero - 1].Transacciones[i].getDia() << " | "
                 << Cliente[cinNumero - 1].Transacciones[i].getMes() << " | "
                 << Cliente[cinNumero - 1].Transacciones[i].getAnio() << endl;
        }
    }else {
        cout<<"Cliente no encontrado"<<endl;
    }
}

void mostrarClientes() {
    for (int i = 0; i < 50; i++) {
        if (Cliente[i].getNumero() != 0) {
            cout << Cliente[i].getNumero() << " | " << Cliente[i].getNombre() << " | " << Cliente[i].getApellido()
                 << " | " << Cliente[i].getTipo() << " | " << Cliente[i].getApertura() << " | "
                 << Cliente[i].getEstado() << endl;
        }
    }
}

void menuExtra() {
    int op = 1;
    while (op > 0 && op < 5) {
        cout << "Ingrese una opcion: " << endl;
        cout << "1.Consultar cliente (por numero)" << endl;
        cout << "2.Mostrar todos los clientes" << endl;
        cout << "3.Transacciones de cliente (por numero)" << endl;
        cout << "4.Informe de transacciones" << endl;
        cin >> op;
        switch (op) {
            case 1:
                consultaPorNumeroCli();
                break;

            case 2: {
                mostrarClientes();
                break;
            }
            case 3: {
                consultaTrPorNumCliente();
                break;
            }
            case 4: {
                menuTiempo();
                break;
            }
        }
    }
}

void leerArchivoCliente(){

    ifstream archivo("Clientes.txt");
    string linea, dato;
    stringstream s;     //linea
    while(getline(archivo, linea, '\n')){

        s.str(linea);

        int cont=-1;

        while(getline(s, dato, ',')){
            cout<<dato<<endl;

            cont++;

                switch (cont) {
                    case 0: {
                        stringstream convertir1;   //Objeto de tipo stringstream

                        convertir1 << dato;      //Colocamos el string en el objeto convertir

                        int number1;           //variable que tendra el string convertido

                        convertir1 >> number1;   //extraemos de 'convertir' el int

                        Cliente[ubicC].setNumero(number1); //buscar conversion de tipo

                        cout<<Cliente[ubicC].getNumero()<<endl;

                        break;
                    }
                    case 1:{
                        Cliente[ubicC].setNombre(dato);

                        break;
                    }
                    case 2:
                        Cliente[ubicC].setApellido(dato);
                        break;
                    case 3:
                        Cliente[ubicC].setTipo(dato);
                        break;
                    case 4:{

                        stringstream convertir2;

                        convertir2 << dato;

                        int number2;

                        convertir2 >> number2;

                        Cliente[ubicC].setApertura(number2);
                        break;
                    }
                    case 5:
                        Cliente[ubicC].setEstado(dato);
                        Cliente[ubicC].setSaldo(0);
                        break;
            }
            cont++;
        }
        s.clear();
        ubicC++;      //en este while me voy elevando a uno en la ubic del cliente
    }

    archivoClientes.close();
}


/*void leerArchivoMov(){
    ifstream archivo ("Movimientos.txt");
    string linea, dato;
    stringstream s;
    while(getline(archivo, linea, '\n')){
        s.str(linea);

        int cont=-1;

       while(getline(s, dato, ',')){
            cout<<dato<<endl;
            cont++;
            switch (cont) {
                case 0:
                    Clientes.Transacciones[ubicT]
                    break;
                case 1:
                    Cliente[ubicC].Transacciones[]
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }
                
            }


        }
*/

int main() {
    int opcion = 1;


//    archivoClientes.open("Clientes.txt");                 //Abrimos el fichero en modo escritura (unica vez)
//    archivoClientes << "--------------LISTADO DE CLIENTES--------------" << endl;
//    archivoClientes.close();
    ifstream fileloaded;

    leerArchivoCliente();
    //leerArchivoMov();
    cout << "Bienvenido a banco UCC" << endl;
    while (opcion > 0 && opcion < 7) {

        cout << '\n' << endl;
        cout << "Menu:" << endl;
        cout << "1.Alta cliente" << endl;               //Listo
        cout << "2.Baja cliente" << endl;               //Listo
        cout << "3.Extraccion de dinero" << endl;       //Listo
        cout << "4.Deposito de dinero" << endl;         //Listo
        cout << "5.Mas opciones" << endl;               //Listo
        cout << "6.Salir" << endl;                      //Listo
        cout << '\n' << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << '\n' << endl;
                altaCliente();
                break;
            case 2:
                cout << '\n' << endl;
                bajaCliente();
                break;
            case 3:
                cout << '\n' << endl;
                extraccion();
                break;
            case 4:
                cout << '\n' << endl;
                deposito();
                break;
            case 5:
                cout << '\n' << endl;
                menuExtra();
                break;
            case 6:
                remove("Clientes.txt");
                opcion=7;
                break;
        }
    }
}
