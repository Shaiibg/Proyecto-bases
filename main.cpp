#include <iostream>
#include "Cliente.h"
#include "ListaLigada.h"

using namespace std;

void menu() {
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Mostrar Clientes" << endl;
    cout << "3. Guardar en archivo" << endl;
    cout << "4. Cargar desde archivo" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opcion: ";
}

int main() {
    ListaLigada lista;
    int opcion, telefono, creacion;
    string nombre, carro, modelo, servicio;

    do {
        menu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Telefono: ";
            cin >> telefono;
            cin.ignore();
            cout << "Carro: ";
            getline(cin, carro);
            cout << "Modelo: ";
            getline(cin, modelo);
            cout << "Año: ";
            cin >> creacion;
            cin.ignore();
            cout << "Servicio: ";
            getline(cin, servicio);

            lista.insertar(Cliente(nombre, telefono, carro, modelo, creacion, servicio));
            break;

        case 2:
            lista.mostrar();
            break;
        
        case 3:
        	lista.guardar("clientes.txt");
        	break;

        case 4:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 4);

    return 0;
}