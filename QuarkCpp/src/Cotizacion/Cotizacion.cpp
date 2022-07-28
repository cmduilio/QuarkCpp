#include "Cotizacion.h"
#include <iostream>

using namespace std;

Cotizacion::Cotizacion(int Numero, string Fecha, string Hora, string CodigoVendedor, string Prenda, int Cantidad, float Resultado) {
	this->numero = Numero;
	this->fecha = Fecha;
	this->hora = Hora;
	this->codigoVendedor = CodigoVendedor;
	this->prenda = Prenda;
	this->cantidad = Cantidad;
	this->resultado = Resultado;
}
