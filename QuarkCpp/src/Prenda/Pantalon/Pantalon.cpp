#include "Pantalon.h"

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