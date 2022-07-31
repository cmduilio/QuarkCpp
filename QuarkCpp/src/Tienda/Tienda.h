#pragma once

#include <string>
#include <vector>

#include "../Prenda/Prenda.h"

using namespace std;

class Tienda {

public:
	
	Tienda(string Nombre, string Direccion, vector<Prenda*> Listado);

	string GetNombre() { return nombre; };
	string GetDireccion() { return direccion; };
	vector<Prenda*> GetListado() { return listado; };

	Prenda* BuscarPrenda(Prenda* prenda);
private:

	string nombre;
	string direccion;
	vector<Prenda*> listado;

};