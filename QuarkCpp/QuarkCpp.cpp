#include "QuarkCpp.h"

#include <iostream>

#include "src/Vendedor/Vendedor.h"
#include "src/Prenda/Pantalon/Pantalon.h"
#include "src/Prenda/Camisa/Camisa.h"
#include "src/Programa/Programa.h"
#include "src/Tienda/Tienda.h"

using namespace std;

int main()
{

	Programa programa = Programa();

	programa.Start();
	return 0;
}
