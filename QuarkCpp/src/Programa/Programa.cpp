#include "Programa.h"
#include <iostream>
#include <Windows.h>

#include "../Vendedor/Vendedor.h"
#include "../Prenda/Pantalon/Pantalon.h"
#include "../Prenda/Camisa/Camisa.h"
#include "../Cotizacion/Cotizacion.h"
#include "../Tienda/Tienda.h"

using namespace std;
Programa::Programa() {}

void Programa::Start() {
	vector<Prenda*> listado;
	Pantalon* pantalon = new Pantalon(TipoCalidad::Premium, 100, 750, TipoPantalon::Chupin);
	listado.push_back(pantalon);
	pantalon = new Pantalon(TipoCalidad::Standard, 100, 750, TipoPantalon::Chupin);
	listado.push_back(pantalon);
	pantalon = new Pantalon(TipoCalidad::Premium, 100, 750, TipoPantalon::Normal);
	listado.push_back(pantalon);
	pantalon = new Pantalon(TipoCalidad::Standard, 100, 750, TipoPantalon::Normal);
	listado.push_back(pantalon);

	Camisa* camisa = new Camisa(TipoCalidad::Standard, 100, 100, TipoManga::Corta, TipoCuello::Mao);
	listado.push_back(camisa);
	camisa = new Camisa(TipoCalidad::Premium, 100, 100, TipoManga::Corta, TipoCuello::Mao);
	listado.push_back(camisa);

	camisa = new Camisa(TipoCalidad::Standard, 100, 150, TipoManga::Corta, TipoCuello::Comun);
	listado.push_back(camisa);
	camisa = new Camisa(TipoCalidad::Premium, 100, 150, TipoManga::Corta, TipoCuello::Comun);
	listado.push_back(camisa);

	camisa = new Camisa(TipoCalidad::Standard, 100, 75, TipoManga::Larga, TipoCuello::Mao);
	listado.push_back(camisa);
	camisa = new Camisa(TipoCalidad::Premium, 100, 75, TipoManga::Larga, TipoCuello::Mao);
	listado.push_back(camisa);

	camisa = new Camisa(TipoCalidad::Standard, 100, 150, TipoManga::Larga, TipoCuello::Comun);
	listado.push_back(camisa);
	camisa = new Camisa(TipoCalidad::Premium, 100, 150, TipoManga::Larga, TipoCuello::Comun);
	listado.push_back(camisa);

	Tienda tienda = Tienda("Nombre de la tienda", "Direccion de la tienda", listado);
	Vendedor vend = Vendedor("Rogelio", "Gutierrez", "001", &tienda);
	this->vendedor = &vend;

	int opcion = 0;
	while (opcion != 3) {
		system("cls");
		cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << endl;
		DrawLine();
		cout << vendedor->GetTienda()->GetNombre() << " | " << vendedor->GetTienda()->GetDireccion() << endl;
		DrawLine();
		cout << vendedor->GetNombre() << " " << vendedor->GetApellido() << " | " << vendedor->GetCodigo() << endl;
		DrawLine();

		while (opcion > 3 || opcion < 1)
		{
			cout << endl << "SELECCIONE UNA OPCION DEL MENU:" << endl << endl;
			cout << "1) Historial de Cotizaciones" << endl;
			cout << "2) Realizar Cotizacion" << endl;
			cout << "3) Salir" << endl;
			cin >> opcion;
		}

		switch (opcion) {
		case 1:
			MostrarHistorial();
			opcion = 0;
			break;
		case 2:
			Cotizar();
			opcion = 0;
			break;
		default:
			break;
		}
	}

}

void Programa::DrawLine() {
	cout << "------------------------------------------------------------" << endl;
}

void Programa::MostrarHistorial() {
	system("cls");
	cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();
	int index = 0;
	while (index < vendedor->GetCotizaciones().size())
	{
		Cotizacion* cotizacion = vendedor->GetCotizaciones()[index];

		cout << *cotizacion;

		if (index < vendedor->GetCotizaciones().size()-1) {
			cout << endl << endl;
		}
		++index;
	}

	int opcion = 0;
	while (opcion != 3) {
		DrawLine();
		cout << "Presiona 3 para volver al menu principal" << endl;
		DrawLine();
		cin >> opcion;
	}
}

void Programa::Cotizar() {
	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	int opcionPrenda = 0;
	while (opcionPrenda != 1 && opcionPrenda != 2) {
		cout << "PASO 1: Seleccione la prenda a cotizar:" << endl;
		cout << "1) Camisa" << endl;
		cout << "2) Pantalon" << endl;
		cin >> opcionPrenda;
	}
	Prenda* prenda;
	if (opcionPrenda == 1) {
		prenda = CrearCamisa();
	}
	else
	{
		prenda = CrearPantalon();
	}

	system("cls");

	if (!prenda) {
		char continuar;
		DrawLine();
		cout << "Error - Prenda a cotizar inexistente." << endl;
		DrawLine();
		cout << "Precione cualquier tecla para continuar" << endl;
		DrawLine();
		cin >> continuar;
		return;
	}

	int cantidad = 0;

	cout << "INFORMACION:" << endl;
	cout << "EXISTE " << prenda->GetCantidadStock() << " CANTIDAD DE UNIDADES DE STOCK DE LA PRENDA SELECCIONADA" << endl;
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" << endl;
	cin >> cantidad;

	system("cls");

	if (cantidad > prenda->GetCantidadStock()) {
		char continuar;
		DrawLine();
		cout << "Error - Prenda a cotizar inexistente." << endl;
		DrawLine();
		cout << "Precione cualquier tecla para continuar" << endl;
		DrawLine();
		cin >> continuar;
		return;
	}

	Cotizacion* cotizacion = this->vendedor->Cotizar(prenda, cantidad);
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	cout << *cotizacion;

	int opcion = 0;
	while (opcion != 3) {
		DrawLine();
		cout << "Presiona 3 para volver al menu principal" << endl;
		DrawLine();
		cin >> opcion;
	}
	
}

Prenda* Programa::CrearCamisa() {
	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	int opcionPrenda = 0;
	while (opcionPrenda != 1 && opcionPrenda != 2) {
		cout << "Paso 2.a: La camisa a cotizar, Es Manga corta?" << endl;
		cout << "1) Si" << endl;
		cout << "2) No" << endl;
		DrawLine();
		cin >> opcionPrenda;
	}

	TipoManga manga = TipoManga::Larga;
	if (opcionPrenda == 1) {
		manga = TipoManga::Corta;
	}

	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	opcionPrenda = 0;
	while (opcionPrenda != 1 && opcionPrenda != 2) {
		cout << "Paso 2.b: La camisa a cotizar, Es Cuello Mao?" << endl;
		cout << "1) Si" << endl;
		cout << "2) No" << endl;
		DrawLine();
		cin >> opcionPrenda;
	}

	TipoCuello cuello = TipoCuello::Comun;
	if (opcionPrenda == 1) {
		cuello = TipoCuello::Mao;
	}

	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	opcionPrenda = 0;
	while (opcionPrenda != 1 && opcionPrenda != 2) {
		cout << "Paso 3: Seleccione la calidad de la prenda" << endl;
		cout << "1) Standard" << endl;
		cout << "2) Premium" << endl;
		DrawLine();
		cin >> opcionPrenda;
	}

	TipoCalidad calidad = TipoCalidad::Standard;
	if (opcionPrenda == 2) {
		calidad = TipoCalidad::Premium;
	}

	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	float precioUnitario = 0.0f;
	while (precioUnitario == 0.0f) {
		cout << "Paso 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
		DrawLine();
		cin >> precioUnitario;
	}

	Camisa prenda = Camisa(calidad, precioUnitario, 0, manga, cuello);
	return BuscarPrenda(&prenda);
}

Prenda* Programa::CrearPantalon() {
	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	int opcionPrenda = 0;
	while (opcionPrenda != 1 && opcionPrenda != 2) {
		cout << "Paso 2: El Pantalon a cotizar, Es Chupin?" << endl;
		cout << "1) Si" << endl;
		cout << "2) No" << endl;
		DrawLine();
		cin >> opcionPrenda;
	}

	TipoPantalon tipoPantalon = TipoPantalon::Normal;
	if (opcionPrenda == 1) {
		tipoPantalon = TipoPantalon::Chupin;
	}

	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	opcionPrenda = 0;
	while (opcionPrenda != 1 && opcionPrenda != 2) {
		cout << "Paso 3: Seleccione la calidad de la prenda" << endl;
		cout << "1) Standard" << endl;
		cout << "2) Premium" << endl;
		DrawLine();
		cin >> opcionPrenda;
	}

	TipoCalidad calidad = TipoCalidad::Standard;
	if (opcionPrenda == 2) {
		calidad = TipoCalidad::Premium;
	}

	system("cls");
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	DrawLine();
	cout << "Presiona 3 para volver al menu principal" << endl;
	DrawLine();

	float precioUnitario = 0.0f;
	while (precioUnitario == 0.0f) {
		cout << "Paso 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
		DrawLine();
		cin >> precioUnitario;
	}
	Pantalon prenda = Pantalon(calidad, precioUnitario, 0, tipoPantalon);
	return BuscarPrenda(&prenda);
}

Prenda* Programa::BuscarPrenda(Prenda* prenda) {
	return this->vendedor->BuscarPrenda(prenda);
}