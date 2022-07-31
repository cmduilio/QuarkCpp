#include "Camisa.h"
#include <iostream>

using namespace std;

Camisa::Camisa(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock, TipoManga TipoManga, TipoCuello TipoCuello) : Prenda(Calidad, PrecioUnitario, CantidadStock) {
	this->tipoManga = TipoManga;
	this->tipoCuello = TipoCuello;
}

float Camisa::Cotizar() {
	float Resultado = Prenda::Cotizar();
	if (TipoManga::Corta == this->tipoManga) {
		Resultado = Resultado * 0.90;
	}

	if (TipoCuello::Mao == this->tipoCuello) {
		Resultado = Resultado * 1.03;
	}

	return Resultado;
}

void Camisa::toString(std::ostream& os) const {
	os << "Camisa - ";
	if (this->tipoCuello == TipoCuello::Mao) {
		os << "Cuello mao - ";
	}

	if (this->tipoManga == TipoManga::Corta) {
		os << "Manga corta - ";
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

bool Camisa::isEqual(const Prenda& prenda) const {
	const Camisa* camisa = dynamic_cast<const Camisa*>(&prenda);
	if (camisa) {
		return Prenda::isEqual(prenda) && camisa->tipoManga == this->tipoManga && camisa->tipoCuello == this->tipoCuello;
	}

	return false;
}