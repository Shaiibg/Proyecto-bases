#ifndef NODO_H
#define NODO_H
#include "Cliente.h"

class Nodo
{
	public:
	    Cliente cliente;
	    Nodo* siguiente;
	    Nodo(Cliente cliente);
};

#endif