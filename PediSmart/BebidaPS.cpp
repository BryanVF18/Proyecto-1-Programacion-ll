#include "BebidaPS.h"

using namespace std;



BebidaPS::BebidaPS(const string& nombre, double precioBase, bool alcoholica)
    : ProductosPS(nombre, precioBase), alcoholica(alcoholica) {
}

bool BebidaPS::getAlcoholica() const {
    return alcoholica;
}

double BebidaPS::getPrecio() const {
    return precioBase;
}

string BebidaPS::getDescripcion() const {
    string tipo = alcoholica ? "Alcoholica" : "No alcoholica";
    return "\n [Bebida] " + nombre + " (" + tipo + ") - $" + to_string(precioBase);
}

void BebidaPS::escribirenbinario(ofstream& os) const {
    int tipo = 2; 
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);
    os.write(reinterpret_cast<const char*>(&precioBase), sizeof(precioBase));
    os.write(reinterpret_cast<const char*>(&alcoholica), sizeof(alcoholica));
}

void BebidaPS::cargarDesdeBinario(ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
    nombre.resize(tam);
    is.read(&nombre[0], tam);
    is.read(reinterpret_cast<char*>(&precioBase), sizeof(precioBase));
    is.read(reinterpret_cast<char*>(&alcoholica), sizeof(alcoholica));
}

void BebidaPS::escribirenTexto(ofstream& os) const {
    os << "2 " << nombre << " " << precioBase << " " << alcoholica << endl;
}