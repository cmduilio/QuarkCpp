#include "Prenda.h"
#include <iostream>

using namespace std;

Prenda::Prenda(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock) {
	this->calidad = Calidad;
	this->precioUnitario = PrecioUnitario;
	this->cantidadStock = CantidadStock;
}


void Prenda::toString(std::ostream& os) const {
	os << "something" << endl;
}

bool Prenda::isEqual(const Prenda& prenda) const {
	return this->calidad == prenda.calidad && this->precioUnitario == prenda.precioUnitario;
}