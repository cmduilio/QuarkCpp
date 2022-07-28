#pragma once

#include "../Prenda.h"

enum TipoManga { Corta, Larga };
enum TipoCuello { Mao, Comun };

class Camisa : Prenda{

public:

	Camisa(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock, TipoManga TipoManga, TipoCuello TipoCuello);

	float Cotizar() override;
private:
	TipoManga tipoManga;
	TipoCuello tipoCuello;

};