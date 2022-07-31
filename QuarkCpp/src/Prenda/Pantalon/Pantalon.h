#pragma once

#include "../Prenda.h"

enum TipoPantalon {Normal, Chupin};

class Pantalon : public Prenda {

public:

	Pantalon(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock, TipoPantalon TipoPantalon);

	float Cotizar() override;

protected:
	virtual void toString(std::ostream& os) const override;
	virtual bool isEqual(const Prenda& prenda) const override;

private:

	TipoPantalon tipoPantalon;

};