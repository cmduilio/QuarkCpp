#include <iostream>
#include "Tienda.h"

Tienda::Tienda(string Nombre, string Direccion, vector<Prenda*> Listado) {
	this->nombre = Nombre;
	this->direccion = Direccion;
	this->listado = Listado;
}

Prenda* Tienda::BuscarPrenda(Prenda* prenda) {
	Prenda* laPrenda = nullptr;
	int index = 0;
	while (!laPrenda && index < listado.size())	
	{
		if (*prenda == *listado[index]) {
			laPrenda = listado[index];
		}

		++index;
	}
	return laPrenda;
}