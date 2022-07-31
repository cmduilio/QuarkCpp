#include "Vendedor.h"
#include <iostream>
#include <ctime>

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

	time_t now = time(0);
	tm* ltm = localtime(&now);

	string Fecha = to_string(ltm->tm_mday) + "/" + to_string(1+ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
	string Hora = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	string CodigoVendedor = this->codigo;

	float Resultado = Prenda->Cotizar() * Cantidad;

	Cotizacion* Cotiz = new Cotizacion(Numero, Fecha, Hora, CodigoVendedor, Prenda, Cantidad, Resultado);
	this->cotizaciones.push_back(Cotiz);
	return Cotiz;
}

Prenda* Vendedor::BuscarPrenda(Prenda* prenda) {
	return this->tienda->BuscarPrenda(prenda);
}