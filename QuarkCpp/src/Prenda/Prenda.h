#pragma once

enum TipoCalidad {Standard, Premium};

class Prenda {

public:

	Prenda(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock);

	float GetPrecioUnitario() { return precioUnitario; }

	virtual float Cotizar() { 
		float Resultado = precioUnitario;
		if (TipoCalidad::Premium == calidad) {
				Resultado = Resultado * 1.30;
		}
		return Resultado; 
	};
private:

	TipoCalidad calidad;
	float precioUnitario;
	int cantidadStock;


};