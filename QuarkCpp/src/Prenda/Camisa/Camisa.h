#pragma once

#include "../Prenda.h"

enum TipoManga { Corta, Larga };
enum TipoCuello { Mao, Comun };

class Camisa : public Prenda{

public:

	Camisa(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock, TipoManga TipoManga, TipoCuello TipoCuello);

	float Cotizar() override;

protected:
	virtual void toString(std::ostream& os) const override;
	virtual bool isEqual(const Prenda& prenda) const override;

private:
	TipoManga tipoManga;
	TipoCuello tipoCuello;

};