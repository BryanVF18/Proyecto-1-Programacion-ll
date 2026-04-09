#include "ComidaPS.h"

ComidaPS::ComidaPS(const string& nombre, double precioBase, const string& categoria)
	: ProductosPS(nombre, precioBase), categoria(categoria)
{
}

string ComidaPS::getCategoria() const
{
	return categoria;
}

double ComidaPS::getPrecio() const
{
	return precioBase;
}

string ComidaPS::getDescripcion() const
{
	return "\n [COMIDA] "+ nombre +" (" + categoria + ") - $" + to_string(precioBase);
}

void ComidaPS::escribirenbinario(ofstream& os) const {
	int tipo = 1; 
	os.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
	size_t tamNombre = nombre.size();
	os.write(reinterpret_cast<const char*>(&tamNombre), sizeof(tamNombre));
	os.write(nombre.c_str(), tamNombre);
	os.write(reinterpret_cast<const char*>(&precioBase), sizeof(precioBase));
	size_t tamCat = categoria.size();
	os.write(reinterpret_cast<const char*>(&tamCat), sizeof(tamCat));
	os.write(categoria.c_str(), tamCat);
}

void ComidaPS::cargarDesdeBinario(ifstream& is) {
	size_t tam;
	is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
	nombre.resize(tam);
	is.read(&nombre[0], tam);
	is.read(reinterpret_cast<char*>(&precioBase), sizeof(precioBase));
	is.read(reinterpret_cast<char*>(&tam), sizeof(tam));
	categoria.resize(tam);
	is.read(&categoria[0], tam);
}

void ComidaPS::escribirenTexto(ofstream& os) const {
	os << "1\n" << nombre << "\n" << precioBase << "\n" << categoria << "\n";
}