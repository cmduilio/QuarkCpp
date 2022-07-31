#pragma once

#include <string>

using namespace std;
class Prenda;

class Cotizacion {

public:
	Cotizacion(int Numero, string Fecha, string Hora, string CodigoVendedor, Prenda* Prenda, int Cantidad, float Resultado);

	int GetNumero() const { return numero; }
	string GetFecha() const { return fecha; }
	string GetHora() const { return hora; }
	string GetCodigoVendedor() const { return codigoVendedor; }
	Prenda* GetPrenda() const { return prenda; }
	int GetCantidad() const { return cantidad; }
	float GetResultado() const { return resultado; }

	friend ostream& operator<<(ostream& output, const Cotizacion& H);
private:
	int numero;
	string fecha;
	string hora;
	string codigoVendedor;
	Prenda* prenda;
	int cantidad;
	float resultado;
};