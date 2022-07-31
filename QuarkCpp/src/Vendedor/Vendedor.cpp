#include "Vendedor.h"
#include <iostream>

#include "../Cotizacion/Cotizacion.h"
#include "../Prenda/Prenda.h"
#include "../Tienda/Tienda.h"

using namespace std;

Vendedor::Vendedor(string Nombre, string Apellido, string Codigo, Tienda* Tienda) {
	this->nombre = Nombre;
	this->apellido = Apellido;
	this->codigo = Codigo;
	this->tienda = Tienda;
}

Cotizacion* Vendedor::Cotizar(Prenda* Prenda, int Cantidad) {
	int Numero = this->cotizaciones.size() + 1;
	string Fecha = "fecha";
	string Hora = "hora";
	string CodigoVendedor = this->codigo;

	float Resultado = Prenda->Cotizar() * Cantidad;

	Cotizacion* Cotiz = new Cotizacion(Numero, Fecha, Hora, CodigoVendedor, Prenda, Cantidad, Resultado);
	this->cotizaciones.push_back(Cotiz);
	return Cotiz;
}

Prenda* Vendedor::BuscarPrenda(Prenda* prenda) {
	return this->tienda->BuscarPrenda(prenda);
}