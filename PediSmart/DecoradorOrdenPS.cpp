#include "DecoradorOrdenPS.h"

using namespace std;



DecoradorOrdenPS::DecoradorOrdenPS(unique_ptr<ProductosPS> producto)
    : ProductosPS(producto->getName(), producto->getPrecioBase()),
    productoEnvuelto(move(producto)) {
}

double DecoradorOrdenPS::getPrecio() const {
    return productoEnvuelto->getPrecio();
}

string DecoradorOrdenPS::getDescripcion() const {
    return productoEnvuelto->getDescripcion();
}