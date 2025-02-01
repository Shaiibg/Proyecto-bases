#include "ListaLigada.h"
#include <iostream>
#include<fstream>

using namespace std;

ListaLigada::ListaLigada() {
    cabeza = nullptr;
}

void ListaLigada::insertar(Cliente cliente) {
    Nodo* nuevo = new Nodo(cliente);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void ListaLigada::mostrar() {
    Nodo* actual = cabeza;
    if (actual == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }
    while (actual != nullptr) {
        cout << "Nombre: " << actual->cliente.get_nombre() << endl;
        cout << "Telefono: " << actual->cliente.get_telefono() << endl;
        cout << "Carro: " << actual->cliente.get_carro() << endl;
        cout << "Modelo: " << actual->cliente.get_modelo() << endl;
        cout << "Año: " << actual->cliente.get_creacion() << endl;
        cout << "Servicio: " << actual->cliente.get_servicio() << endl;
        cout << "-------------------------------" << endl;
        actual = actual->siguiente;
    }
}

void ListaLigada::guardar(string nombreArchivo){
	ofstream archivo(nombreArchivo); 

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return; 
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        archivo << actual->cliente.get_nombre() << ","
                << actual->cliente.get_telefono() << ","
                << actual->cliente.get_carro() << ","
                << actual->cliente.get_modelo() << ","
                << actual->cliente.get_creacion() << ","
                << actual->cliente.get_servicio() << endl;
        actual = actual->siguiente;
    }

    archivo.close(); 
    cout << "Datos guardados correctamente en " << nombreArchivo << endl;
}

