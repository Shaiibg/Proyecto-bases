#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "Cliente.h"
#include "Nodo.h"

class ListaLigada {
    public:
        ListaLigada();
        void insertar(Cliente cliente);//ya
        void mostrar();//ya
        void guardar(string nombreArchivo);//ya
        void cargarArchivo(string nombreArchivo);
        void modificar();
    private:
        Nodo* cabeza;
};

#endif
