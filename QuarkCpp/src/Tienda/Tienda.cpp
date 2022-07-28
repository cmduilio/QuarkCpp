
#include "Tienda.h"

Tienda::Tienda(string Nombre, string Direccion, vector<Prenda*> Listado) {
	this->nombre = Nombre;
	this->direccion = Direccion;
	this->listado = Listado;
}