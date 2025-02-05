#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "Cliente.h"
#include "Nodo.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class ListaLigada {
public:
    ListaLigada();
    void insertar(Cliente cliente);
    void mostrar();
    bool guardar(const string& nombreArchivo);
    bool cargarArchivo(const string& nombreArchivo);
    bool modificarCliente(const string& nombre);
    bool eliminarCliente(const string& nombre);
    ~ListaLigada(); 

private:
    Nodo* cabeza;
    void liberarMemoria(); 
    Nodo* encontrarCliente(const string& nombre);
};

#endif