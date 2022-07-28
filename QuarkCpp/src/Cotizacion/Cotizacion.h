#pragma once

#include <string>

using namespace std;

class Cotizacion {

public:
	Cotizacion(int Numero, string Fecha, string Hora, string CodigoVendedor, string Prenda, int Cantidad, float Resultado);

private:
	int numero;
	string fecha;
	string hora;
	string codigoVendedor;
	string prenda;
	int cantidad;
	float resultado;
};