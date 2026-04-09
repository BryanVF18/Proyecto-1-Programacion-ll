#include "PersonalizacionPS.h"

using namespace std;



PersonalizacionPS::PersonalizacionPS(unique_ptr<ProductosPS> producto)
    : DecoradorOrdenPS(move(producto)),
    tamanio("Normal"),
    factorPrecio(1.0) {
}

void PersonalizacionPS::agregarIngrediente(const string& ingrediente, double costo) {
    ingredientesExtra.push_back({ ingrediente, costo });
}

void PersonalizacionPS::quitarIngrediente(const string& ingrediente) {
    ingredientesRemovidos.push_back(ingrediente);
}

void PersonalizacionPS::cambiarTamanio(const string& t, double factor) {
    tamanio = t;
    factorPrecio = factor;
}

double PersonalizacionPS::getPrecio() const {
    double total = productoEnvuelto->getPrecio() * factorPrecio;
    for (const auto& extra : ingredientesExtra) {
        total += extra.second;
    }
    return total;
}

string PersonalizacionPS::getDescripcion() const {
    string desc = "[" + tamanio + "] " + productoEnvuelto->getDescripcion();
    for (const auto& extra : ingredientesExtra) {
        desc += " + " + extra.first;
    }
    for (const auto& removido : ingredientesRemovidos) {
        desc += " sin " + removido;
    }
    return desc;
}