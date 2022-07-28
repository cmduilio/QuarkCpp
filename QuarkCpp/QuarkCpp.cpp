#include "QuarkCpp.h"

#include <iostream>

#include "src/Vendedor/Vendedor.h"
#include "src/Prenda/Prenda.h"
#include "src/Prenda/Pantalon/Pantalon.h"

int main()
{
	vector<Prenda*> listado;
	Tienda tienda = Tienda("Nombre", "direccion", listado);
	Vendedor Vend = Vendedor("Nombre", "apellido", "001", tienda);

	Vend.Cotizar(1, "Fecha", "Hora", "Codigo", "Prenda", 3, 20);

	Pantalon prenda = Pantalon(TipoCalidad::Premium, 100, 5, TipoPantalon::Chupin);

	Prenda* asd = &prenda;

	listado.push_back(&prenda);
	
	float valor = listado[0]->Cotizar();

	std::cout << valor << endl;

	return 0;
}
