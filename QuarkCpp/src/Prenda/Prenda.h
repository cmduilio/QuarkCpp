#pragma once
#include <iostream>
#include <string>

using namespace std;

enum TipoCalidad {Standard, Premium};

class Prenda {

public:

	Prenda(TipoCalidad Calidad, float PrecioUnitario, int CantidadStock);

	float GetPrecioUnitario() { return precioUnitario; }
	float GetCantidadStock() { return cantidadStock; }

	virtual float Cotizar() { 
		float Resultado = precioUnitario;
		if (TipoCalidad::Premium == calidad) {
			Resultado = Resultado * 1.30;
		}

		return Resultado; 
	};

	friend ostream& operator<<(std::ostream& os, const Prenda& prenda) {
		prenda.toString(os);
		return os;
	};

	friend bool operator==(const Prenda& p1, const Prenda& p2) 
	{
		return p1.isEqual(p2);
	}

	virtual bool isEqual(const Prenda& prenda) const;

protected:
	virtual void toString(std::ostream& os) const;

	TipoCalidad calidad;
	float precioUnitario;
	int cantidadStock;


};