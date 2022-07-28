#include "Vendedor.h"
#include <iostream>

using namespace std;

Vendedor::Vendedor(string Nombre, string Apellido, string Codigo, Tienda tienda) {
	this->nombre = Nombre;
	this->apellido = Apellido;
	this->codigo = Codigo;
}

void Vendedor::Cotizar(int Numero, string Fecha, string Hora, string CodigoVendedor, string Prenda, int Cantidad, float Resultado) {
	cout << "cotizando..." << endl;
	Cotizacion Cotiz = Cotizacion(Numero, Fecha, Hora, CodigoVendedor, Prenda, Cantidad, Resultado);
	this->cotizaciones.push_back(Cotiz);
}