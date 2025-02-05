#include <iostream>
#include <limits>
#include <algorithm>
#include "ListaLigada.h"

using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validarNumero(int& numero, const string& mensaje) {
    cout << mensaje;
    if (!(cin >> numero)) {
        cout << "Error: Ingrese un valor numerico valido." << endl;
        limpiarBuffer();
        return false;
    }
    limpiarBuffer();
    return true;
}

string toLowerCase(const string& str) {
    string resultado = str;
    transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    return resultado;
}

void menu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Mostrar Clientes" << endl;
    cout << "3. Modificar Cliente" << endl;
    cout << "4. Eliminar Cliente" << endl;
    cout << "5. Guardar y salir" << endl;
    cout << "\nSelecciona una opcion: ";
}

int main() {
    ListaLigada lista;
    int opcion, telefono, creacion;
    string nombre, carro, modelo, servicio;
    lista.cargarArchivo("clientes.txt");

    do {
        menu();
        if (!validarNumero(opcion, "")) {
            continue;
        }

        switch (opcion) {
        case 1: {
            cout << "\n=== AGREGAR NUEVO CLIENTE ===\n" << endl;
            cout << "Nombre: ";
            getline(cin, nombre);
            
            do {
                if (!validarNumero(telefono, "Telefono: ")) {
                    continue;
                }
                break;
            } while (true);
            
            cout << "Carro: ";
            getline(cin, carro);
            
            cout << "Modelo: ";
            getline(cin, modelo);
            
            do {
                if (!validarNumero(creacion, "Año: ")) {
                    continue;
                }
                break;
            } while (true);
            
            do {
                cout << "Servicio (B) Basico, (F) Frenos, (C) Completo: ";
                getline(cin, servicio);
                servicio = toLowerCase(servicio);
                
                if (servicio == "b") {
                    servicio = "Basico";
                } else if (servicio == "f") {
                    servicio = "Frenos";
                } else if (servicio == "c") {
                    servicio = "Completo";
                } else {
                    cout << "Error: Servicio no válido. Intente nuevamente." << endl;
                    continue;
                }
                break;
            } while (true);
            
            lista.insertar(Cliente(nombre, telefono, carro, modelo, creacion, servicio));
            cout << "\nCliente agregado exitosamente!" << endl;
            break;
        }
        case 2:
            lista.mostrar();
            break;
        case 3: {
            string nombreModificar;
            cout << "Ingrese el nombre del cliente a modificar: ";
            getline(cin, nombreModificar);
            lista.modificarCliente(nombreModificar);
            break;
        }
        case 4: {
            string nombreEliminar;
            cout << "Ingrese el nombre del cliente a eliminar: ";
            getline(cin, nombreEliminar);
            if (lista.eliminarCliente(nombreEliminar)) {
                lista.guardar("clientes.txt");
            }
            break;
        }
        case 5:
            lista.guardar("clientes.txt");
            break;
        default:
            cout << "\nError: Opcion no valida. Por favor, seleccione una opcion del menu." << endl;
        }
    } while (opcion != 5);
    system("pause");
    
    return 0;
}