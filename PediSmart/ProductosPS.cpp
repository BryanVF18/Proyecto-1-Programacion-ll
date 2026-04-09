#include "ProductosPS.h"

ProductosPS::ProductosPS(const string& nombre, double precioBase)
	: nombre(nombre), precioBase(precioBase)
{
}

string ProductosPS::getName() const
{
	return nombre;
}

double ProductosPS::getPrecioBase() const
{
	return precioBase;
}