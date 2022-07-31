# CMakeList.txt : CMake project for QuarkCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (QuarkCpp "QuarkCpp.cpp" "QuarkCpp.h" "src/Vendedor/Vendedor.h" "src/Vendedor/Vendedor.cpp" "src/Cotizacion/Cotizacion.cpp" "src/Cotizacion/Cotizacion.h" "src/Tienda/Tienda.h" "src/Tienda/Tienda.cpp" "src/Prenda/Prenda.h" "src/Prenda/Prenda.cpp" "src/Prenda/Camisa/Camisa.cpp" "src/Prenda/Camisa/Camisa.h" "src/Prenda/Pantalon/Pantalon.cpp" "src/Prenda/Pantalon/Pantalon.h" "src/Programa/Programa.h" "src/Programa/Programa.cpp")

# TODO: Add tests and install targets if needed.
