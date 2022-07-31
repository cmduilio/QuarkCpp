#include "Pantalon.h"
#include <iostream>

using namespace std;

Pantalon::Pantalon(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock, TipoPantalon TipoPantalon)
	:Prenda(Calidad, PrecioUnitario, CantidadStock){
	this->tipoPantalon = TipoPantalon;
}

float Pantalon::Cotizar() {
	float Resultado = Prenda::Cotizar();
	if (TipoPantalon::Chupin == this->tipoPantalon) {
		Resultado = Resultado * 0.88;
	}
	return Resultado;
}

void Pantalon::toString(std::ostream& os) const {
	os << "Pantalon - ";
	if (this->tipoPantalon == TipoPantalon::Chupin) {
		os << "Pantalon Chupin - ";
	}

	if (this->calidad == TipoCalidad::Premium) {
		os << "Premium";
	}
	else
	{
		os << "Standard";
	}

	os << endl;
}

bool Pantalon::isEqual(const Prenda& prenda) const {
	const Pantalon* pantalon = dynamic_cast<const Pantalon*>(&prenda);

	if (pantalon) {
		return Prenda::isEqual(prenda) && pantalon->tipoPantalon == this->tipoPantalon;
	}

	return false;
}