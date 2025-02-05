#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

using namespace std;

class Cliente
{
	private:
		string nombre;
		int telefono;
		string carro;
		string modelo;
		int creacion;
		string servicio;
	public:
		Cliente(string, int, string, string, int, string);
		
		void set_nombre(string);
		void set_telefono(int);
		void set_carro(string);
		void set_modelo(string);
		void set_creacion(int);
		void set_servicio(string);
		
		string get_nombre();
		int get_telefono();
		string get_carro();
		string get_modelo();
		int get_creacion();
		string get_servicio();
};

#endif
#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

using namespace std;

class Cliente
{
	private:
		string nombre;
		int telefono;
		string carro;
		string modelo;
		int creacion;
		string servicio;
	public:
		Cliente(string, int, string, string, int, string);
		
		void set_nombre(string);
		void set_telefono(int);
		void set_carro(string);
		void set_modelo(string);
		void set_creacion(int);
		void set_servicio(string);
		
		string get_nombre();
		int get_telefono();
		string get_carro();
		string get_modelo();
		int get_creacion();
		string get_servicio();
};

#endif