#pragma once

#include <string>
#include <vector>
#include "../Cotizacion/Cotizacion.h"
#include "../Tienda/Tienda.h"

using namespace std;

class Vendedor {

public:
	Vendedor(string Nombre, string Apellido, string Codigo, Tienda tienda);

	void Cotizar(int Numero, string Fecha, string Hora, string CodigoVendedor, string Prenda, int Cantidad, float Resultado);

private:
	string nombre;
	string apellido;
	string codigo;
	vector<Cotizacion> cotizaciones;
};