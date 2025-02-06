#include "Cliente.h"


Cliente::Cliente(string nombre, int telefono, string carro, string modelo, int creacion, string servicio){
    this->nombre = nombre;
    this->telefono = telefono;
    this->carro = carro;
    this->modelo = modelo;
    this->creacion = creacion;
    this->servicio = servicio;
}


void Cliente::set_nombre(string nombre){
    this->nombre = nombre;
}

void Cliente::set_telefono(int telefono){
    this->telefono = telefono;
}

void Cliente::set_carro(string carro){
    this->carro = carro;
}

void Cliente::set_modelo(string modelo){
    this->modelo = modelo;
}

void Cliente::set_creacion(int creacion){
    this->creacion = creacion;
}

void Cliente::set_servicio(string servicio){
    this->servicio = servicio;
}

string Cliente::get_nombre(){
    return this->nombre;
}

int Cliente::get_telefono(){
    return this->telefono;
}

string Cliente::get_carro(){
    return this->carro;
}

string Cliente::get_modelo(){
    return this->modelo;
}

int Cliente::get_creacion(){
    return this->creacion;
}

string Cliente::get_servicio(){
    return this->servicio;
}