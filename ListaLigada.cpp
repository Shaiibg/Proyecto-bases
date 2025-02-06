#include "ListaLigada.h"
#include <iostream>
#include <algorithm>

ListaLigada::ListaLigada(){
    cabeza=nullptr;
}

ListaLigada::~ListaLigada(){
    liberarMemoria();
}

void ListaLigada::liberarMemoria(){
    while (cabeza!=nullptr){
        Nodo* temp=cabeza;
        cabeza=cabeza->siguiente;
        delete temp;
    }
}

void ListaLigada::insertar(Cliente cliente){
    Nodo* nuevo=new Nodo(cliente);
    if (cabeza==nullptr){
        cabeza=nuevo;
    }else{
        Nodo* actual=cabeza;
        while (actual->siguiente!=nullptr){
            actual=actual->siguiente;
        }
        actual->siguiente=nuevo;
    }
}

void ListaLigada::mostrar(){
    Nodo* actual = cabeza;
    if (actual == nullptr){
        cout << "\nLa lista esta vacia."<<endl;
        return;
    }
    cout << "\n=== LISTA DE CLIENTES ===\n"<<endl;
    while (actual != nullptr){
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

bool ListaLigada::guardar(const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "Error: No se pudo abrir el archivo para escritura." << endl;
        return false;
    }
    
    try{
        Nodo* actual = cabeza;
        while(actual != nullptr){
            archivo << actual->cliente.get_nombre() << ","
                   << actual->cliente.get_telefono() << ","
                   << actual->cliente.get_carro() << ","
                   << actual->cliente.get_modelo() << ","
                   << actual->cliente.get_creacion() << ","
                   << actual->cliente.get_servicio() << endl;
            actual = actual->siguiente;
        }
        archivo.close();
        cout << "Datos guardados correctamente en "<<nombreArchivo <<endl;
        return true;
    } catch (const exception& e){
        archivo.close();
        cout<<"Error al guardar los datos: "<<e.what()<<endl;
        return false;
    }
}

bool ListaLigada::cargarArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout<<"Error: No se pudo abrir el archivo para lectura."<<endl;
        return false;
    }

    try{
        liberarMemoria(); 
        string linea, nombre, carro, modelo, servicio;
        int telefono, creacion;
        
        while (getline(archivo, linea)){
            stringstream ss(linea);
            
            getline(ss, nombre, ',');
            ss >> telefono;
            ss.ignore();
            getline(ss, carro, ',');
            getline(ss, modelo, ',');
            ss >> creacion;
            ss.ignore();
            getline(ss, servicio);
            
            insertar(Cliente(nombre, telefono, carro, modelo, creacion, servicio));
        }
        
        archivo.close();
        cout<<"Datos cargados correctamente desde "<<nombreArchivo<<endl;
        return true;
    } catch (const exception& e){
        archivo.close();
        cout << "Error al cargar los datos: " << e.what()<<endl;
        return false;
    }
}

Nodo* ListaLigada::encontrarCliente(const string& nombre){
    Nodo* actual=cabeza;
    while (actual!=nullptr) {
        if (actual->cliente.get_nombre()==nombre){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool ListaLigada::modificarCliente(const string& nombre){
    Nodo* nodoCliente = encontrarCliente(nombre);
    if (nodoCliente == nullptr){
        cout << "Cliente no encontrado."<<endl;
        return false;
    }

    int opcion;
    cout<<"\n=== MODIFICAR CLIENTE ==="<<endl;
    cout<<"1. Modificar Nombre"<<endl;
    cout<<"2. Modificar Telefono"<<endl;
    cout<<"3. Modificar Carro"<<endl;
    cout<<"4. Modificar Modelo"<<endl;
    cout<<"5. Modificar Año"<<endl;
    cout<<"6. Modificar Servicio"<<endl;
    cout<<"Seleccione el dato a modificar: ";
    cin>>opcion;
    cin.ignore();

    switch (opcion){
        case 1: {
            string nuevoNombre;
            cout << "Nuevo nombre: ";
            getline(cin, nuevoNombre);
            nodoCliente->cliente.set_nombre(nuevoNombre);
            break;
        }
        case 2:{
            int nuevoTelefono;
            cout << "Nuevo telefono: ";
            cin >> nuevoTelefono;
            cin.ignore();
            nodoCliente->cliente.set_telefono(nuevoTelefono);
            break;
        }
        case 3:{
            string nuevoCarro;
            cout<<"Nuevo carro: ";
            getline(cin, nuevoCarro);
            nodoCliente->cliente.set_carro(nuevoCarro);
            break;
        }
        case 4:{
            string nuevoModelo;
            cout<<"Nuevo modelo: ";
            getline(cin, nuevoModelo);
            nodoCliente->cliente.set_modelo(nuevoModelo);
            break;
        }
        case 5:{
            int nuevoAno;
            cout<<"Nuevo año: ";
            cin>>nuevoAno;
            cin.ignore();
            nodoCliente->cliente.set_creacion(nuevoAno);
            break;
        }
        case 6: {
            string nuevoServicio;
            do {
                cout << "Nuevo Servicio (B) Basico, (F) Frenos, (C) Completo: ";
                getline(cin, nuevoServicio);
                
                transform(nuevoServicio.begin(), nuevoServicio.end(), nuevoServicio.begin(), ::tolower);
                
                if (nuevoServicio == "b"){
                    nuevoServicio = "Basico";
                }else if (nuevoServicio == "f"){
                    nuevoServicio = "Frenos";
                }else if (nuevoServicio == "c"){
                    nuevoServicio = "Completo";
                }else {
                    cout << "Error: Servicio no valido. Intente nuevamente." << endl;
                    continue;
                }
                break;
            } while (true);
            
            nodoCliente->cliente.set_servicio(nuevoServicio);
            break;
        }
        default: {
            cout << "Opcion no valida." << endl;
            return false;
        }
    }

    cout<<"Cliente modificado exitosamente."<<endl;
    return true;
}

bool ListaLigada::eliminarCliente(const string& nombre){
    if (cabeza == nullptr){
        cout << "La lista está vacía."<<endl;
        return false;
    }

    
    if (cabeza->cliente.get_nombre() == nombre){
        Nodo* temp=cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cout << "Cliente eliminado exitosamente." << endl;
        return true;
    }

    
    Nodo* actual=cabeza;
    while (actual->siguiente!=nullptr){
        if (actual->siguiente->cliente.get_nombre()==nombre){
            Nodo* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            cout<<"Cliente eliminado exitosamente."<<endl;
            return true;
        }
        actual=actual->siguiente;
    }

    cout<<"Cliente no encontrado."<<endl;
    return false;
}