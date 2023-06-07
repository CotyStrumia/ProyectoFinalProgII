#include <iostream>
#include <string>
#include <fstream>
#include "Clientes.h"
using namespace std;

Clientes Cliente[50];          //Instanciacion por defecto de nuestra base de datos de los clientes
int ubicC = 0;                 //Declaracion de variables globales en constante uso
int nro_T = 0;
ofstream archivoClientes;      //Declaramos archivo txt como variable global

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
                if (cAnio < 0 || cAnio > 2023) {
                    return false;
                }
                return true;
            } else if (cMes < 0 || cMes > 12) {
                return false;
            }
        }
    }
}

bool verificadorAlta(int cAnio) {
    if (cAnio < 0 || cAnio > 2023) {
        return false;
    } else {
        return true;
    }
}

void trSeisMeses(){
    for(int i=0; i<50; i++) {
        if (Cliente[i].Transacciones[i].getAnio() == 2023 && Cliente[i].Transacciones[i].getMes()>0 && Cliente[i].Transacciones[i].getMes()<7){
          Cliente[i].Transacciones[i].mostrarTransaccion();
        }
    }

}

void trAnio() {
    for(int i=0; i<50; i++){
        if(Cliente[i].Transacciones[i].getAnio() == 2023 && Cliente[i].Transacciones[i].getAnio() == 2022 && Cliente[i].Transacciones[i].getMes() > 0 && Cliente[i].Transacciones[i].getMes() < 7){
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

        //Llamamos a una funcion que evalue segun la opcion ingresada asi no hacemos un switch
    }
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
            cout << "Los clientes con una antiguedad menor a 3 años no pueden ser de tipo black" << endl;

        } else {

            Cliente[ubicC] = Clientes(num, cinNombre, cinApellido, cinTipo, cinApertura, "Activo", 0);

            cout << "Se le ha dado alta al cliente: " << Cliente[ubicC].getNombre() << " "
                 << Cliente[ubicC].getApellido() << ", numero " << num << " exitosamente" << endl;

            if (archivoClientes.is_open()) {

                archivoClientes << '\n' << endl;
                archivoClientes << "Numero de cliente:" << Cliente[ubicC].getNumero() << endl;
                archivoClientes << "Nombre: " << Cliente[ubicC].getNombre()<<endl;
                archivoClientes << "Apellido: " << Cliente[ubicC].getApellido() << endl;
                archivoClientes << "Tipo: " << Cliente[ubicC].getTipo() << endl;
                archivoClientes << "Apertura (anio): " << Cliente[ubicC].getApertura() << endl;
                archivoClientes << "Estado" << Cliente[ubicC].getEstado() << endl;
                ifstream fileloaded;

            } else {
                archivoClientes.open("Clientes.txt");
                archivoClientes << "LISTA DE CLIENTES" << endl;
                archivoClientes << "Numero de cliente:" << Cliente[ubicC].getNumero() << endl;
                archivoClientes << "Nombre: " << Cliente[ubicC].getNombre();
                archivoClientes << "Apellido: " << Cliente[ubicC].getApellido() << endl;
                archivoClientes << "Tipo: " << Cliente[ubicC].getTipo() << endl;
                archivoClientes << "Apertura (anio): " << Cliente[ubicC].getApertura() << endl;
                archivoClientes << "Estado" << Cliente[ubicC].getEstado() << endl;
                ifstream fileloaded;
            }

            ubicC++;
        }
    } else {
        cout << "Año invalido" << endl;
    }
}

void bajaCliente() {
    int cinNumero;
    cout << "Ingrese el numero de cliente" << endl;
    cin >> cinNumero;

    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {
            Cliente[j].baja(cinNumero);

            archivoClientes << '\n' << endl;
            archivoClientes << "Estado" << Cliente[ubicC].getEstado() << endl;
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

    cout << "Ingrese su numero de cliente" << endl;
    cin >> cinNumero;

    if (verificarFecha(dia, mes, anio)) {

        for (i = 0; i < 50; i++) {
            if (Cliente[i].getNumero() == cinNumero && Cliente[i].getEstado() == "Activo") {

                cout << "Ingrese el monto a extraer" << endl;
                cin >> cinMonto;

                if (cinMonto <= Cliente[i].getSaldo() && cinMonto > 0) {

                    Cliente[i].setSaldo(Cliente[i].getSaldo() - cinMonto);

                    cout << "SU MONTO ACTUALIZADO ES DE: " << Cliente[i].getSaldo() << endl;

                    Cliente[i].Transacciones[nro_T] = Transacciones(nro_T + 1, Cliente[i].getSaldo(), cinMonto, 'E',
                                                                    dia, mes, anio);

                    Cliente[i].Transacciones[nro_T].mostrarTransaccion();
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

    cout << "Ingrese su numero de cliente" << endl;
    cin >> cinNumero;

    if (verificarFecha(dia, mes, anio)) {
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
    }else {
        cout<<"La fecha ingresada es invalida"<<endl;
    }

}

void consultaPorNumeroCli() {
    int cinNumero;
    cout << "Ingrese el numero de cliente" << endl;
    cin >> cinNumero;
    for (int j = 0; j < 50; j++) {
        if (Cliente[j].getNumero() == cinNumero) {
            Cliente[j].mostrarCliente();
        }
    }
}

void consultaPorNumTr() {
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

    Cliente[ubicC] = Clientes(ubicC + 1, "Bautista", "Juncos", "black", 2020, "Activo", 100);
    cout << Cliente[ubicC].getNumero() << endl;
    cout << Cliente[ubicC].getNombre() << endl;
    cout << Cliente[ubicC].getApellido() << endl;
    cout << Cliente[ubicC].getTipo() << endl;
    cout << Cliente[ubicC].getApertura() << endl;
    cout << Cliente[ubicC].getEstado() << endl;

    cout << "Bienvenido a banco UCC" << endl;
    while (opcion > 0 && opcion < 8) {

        cout << "Menu:" << endl;
        cout << "1.Alta cliente" << endl;               //Listo
        cout << "2.Baja cliente" << endl;               //Listo
        cout << "3.Extraccion de dinero" << endl;       //Listo
        cout << "4.Deposito de dinero" << endl;         //Listo
        cout << "5.Mas opciones" << endl;
        cout << "6.Descargar base de datos clientes" << endl;
        cout << "7.Descargar base de datos transacciones" << endl;
        cout << "8.Salir" << endl;
        cin >> opcion;

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
            case 6:
                //
                break;
            case 7:
                //
                break;
        }
    }
}
