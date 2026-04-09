#include "PedidoPS.h"
#include "ExcepcionesPS.h"
#include <sstream>
#include <iostream>


using namespace std;



PedidoPS::PedidoPS(int id, shared_ptr<ClientePS> cliente)
    : id(id), cliente(cliente), descuento(0.0) {
}

int PedidoPS::getId() const {
    return id;
}

shared_ptr<ClientePS> PedidoPS::getCliente() const {
    return cliente;
}

const vector<shared_ptr<ProductosPS>>& PedidoPS::getProductos() const {
    return productos;
}

double PedidoPS::getDescuento() const {
    return descuento;
}

void PedidoPS::agregarProducto(shared_ptr<ProductosPS> producto) {
	productos.push_back(producto);
}

double PedidoPS::calcularTotal() const {
    try {
        if (productos.empty()) throw PedidoVacioExcep();
        double total = 0.0;
        for (const auto& p : productos) {
            total += p->getPrecio();
        }
        return total * (1.0 - descuento / 100.0);
    }
    catch (const PedidoVacioExcep& e) {
        cout << e.what() << endl;
        return 0.0;
    }
}

void PedidoPS::aplicarDescuento(double porcentaje) {
    try {
        if (porcentaje < 0 || porcentaje > 100)
            throw EntradaInvalidaExcep("El descuento debe estar entre 0 y 100.");
        descuento = porcentaje;
    }
    catch (const EntradaInvalidaExcep& e) {
        cout << e.what() << endl;
    }
}

string PedidoPS::toString() const {
    ostringstream oss;
    oss << "Pedido #" << id << " | " << cliente->toString() << "\n";
    for (const auto& p : productos) {
        oss << "  - " << p->getDescripcion() << "\n";
    }
    oss << "  Descuento: " << descuento << "%\n";
    oss << "  Total: $" << calcularTotal() << "\n";
    return oss.str();
}

void PedidoPS::limpiarProductos() {
    productos.clear();
}