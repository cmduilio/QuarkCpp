#pragma once

class Vendedor;
class Prenda;

class Programa {

public:
	Programa();

	void Start();
private:
	Vendedor* vendedor;

	void DrawLine();
	void MostrarHistorial();
	void Cotizar();
	Prenda* CrearCamisa();
	Prenda* CrearPantalon();
	Prenda* BuscarPrenda(Prenda* prenda);
};