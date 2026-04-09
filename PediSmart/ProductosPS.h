
#ifndef PRODUCTOS_PS_H
#define PRODUCTOS_PS_H

#include <string>
using namespace std;


class ProductosPS {
protected:
	string nombre;
	double precioBase;
public:
	ProductosPS(const string& nombre, double precioBase);
	virtual ~ProductosPS() = default;
	string getName() const;
	double getPrecioBase() const;
	virtual double getPrecio() const = 0;
	virtual string getDescripcion() const = 0;
	virtual void escribirenbinario(ofstream& os) const = 0;
	virtual void cargarDesdeBinario(ifstream& is) = 0;
	virtual void escribirenTexto(ofstream& os) const = 0;
};

#endif