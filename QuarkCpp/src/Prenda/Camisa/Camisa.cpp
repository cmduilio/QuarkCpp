#include "Camisa.h"


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