#pragma once

#include <string>
#include <vector>

using namespace std;

class Cotizacion;
class Tienda;
class Prenda;

class Vendedor {

public:
	Vendedor(string Nombre, string Apellido, string Codigo, Tienda* tienda);

	Cotizacion* Cotizar(Prenda* Prenda, int Cantidad);

	string GetNombre(){ return nombre; };
	string GetApellido(){ return apellido; };
	string GetCodigo() { return codigo; };
	vector<Cotizacion*> GetCotizaciones() { return cotizaciones; };
	Tienda* GetTienda() { return tienda; }

	Prenda* BuscarPrenda(Prenda* prenda);

private:
	string nombre;
	string apellido;
	string codigo;
	Tienda* tienda;
	vector<Cotizacion*> cotizaciones;
};