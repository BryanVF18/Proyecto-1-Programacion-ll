#include "PostresPS.h"

using namespace std;



PostresPS::PostresPS(const string& nombre, double precioBase, bool vegano)
    : ProductosPS(nombre, precioBase), vegano(vegano) {
}

bool PostresPS::getVegano() const {
    return vegano;
}

double PostresPS::getPrecio() const {
    return precioBase;
}

string PostresPS::getDescripcion() const {
    string tipo = vegano ? "Vegano" : "No vegano";
    return "\n [Postre] " + nombre + " (" + tipo + ") - $" + to_string(precioBase);
}

void PostresPS::escribirenbinario(ofstream& os) const {
    int tipo = 3; 
    os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
    size_t tamNombre = nombre.size();
    os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
    os.write(nombre.c_str(), tamNombre);
    os.write(reinterpret_cast<const char*>(&precioBase), sizeof(precioBase));
    os.write(reinterpret_cast<const char*>(&vegano), sizeof(vegano));
}

void PostresPS::cargarDesdeBinario(ifstream& is) {
    size_t tam;
    is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
    nombre.resize(tam);
    is.read(&nombre[0], tam);
    is.read(reinterpret_cast<char*>(&precioBase), sizeof(precioBase));
    is.read(reinterpret_cast<char*>(&vegano), sizeof(vegano));
}

void PostresPS::escribirenTexto(ofstream& os) const {
    os << "3\n" << nombre << "\n" << precioBase << "\n" << vegano << "\n";
}