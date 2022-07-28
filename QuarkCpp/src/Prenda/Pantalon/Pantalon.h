#pragma once

#include "../Prenda.h"

enum TipoPantalon {Comun, Chupin};

class Pantalon : public Prenda {

public:

	Pantalon(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock, TipoPantalon TipoPantalon);

	float Cotizar() override;

private:

	TipoPantalon tipoPantalon;

};