#pragma once

#include <string>
#include <vector>

#include "../Prenda/Prenda.h"

using namespace std;

class Tienda {

public:
	
	Tienda(string Nombre, string Direccion, vector<Prenda*> Listado);

private:

	string nombre;
	string direccion;
	vector<Prenda*> listado;

};