#include "Cotizacion.h"
#include <iostream>

#include "../Prenda/Prenda.h"

using namespace std;

Cotizacion::Cotizacion(int Numero, string Fecha, string Hora, string CodigoVendedor, Prenda* Prenda, int Cantidad, float Resultado) {
	this->numero = Numero;
	this->fecha = Fecha;
	this->hora = Hora;
	this->codigoVendedor = CodigoVendedor;
	this->prenda = Prenda;
	this->cantidad = Cantidad;
	this->resultado = Resultado;
}

ostream& operator<<(std::ostream& os, const Cotizacion& cotizacion)
{
	os << "Numero de identificacion: " << cotizacion.GetNumero() << endl;
	os << "Fecha y Hora de la cotizacion:: " << cotizacion.GetFecha() << " " << cotizacion.GetHora() << endl;
	os << "Codigo del vendedor: " << cotizacion.GetNumero() << endl;
	os << "Prenda cotizada: : " << *(cotizacion.GetPrenda());
	os << "Precio unitario: $" << cotizacion.GetPrenda()->GetPrecioUnitario() << endl;
	os << "Cantidad de unidades cotizadas: " << cotizacion.GetCantidad() << endl;
	os << "Precio Final: $" << cotizacion.GetResultado() << endl;
	return os;
}