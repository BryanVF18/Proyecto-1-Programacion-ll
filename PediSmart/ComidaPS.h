#ifndef COMIDA_PS_H
#define COMIDA_PS_H

#include "ProductosPS.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



class ComidaPS : public ProductosPS {
private:
    string categoria;

public:
    ComidaPS(const string& nombre, double precioBase, const string& categoria);

    string getCategoria() const;
	double getPrecio() const override;
    string getDescripcion() const override;
	void escribirenbinario(ofstream& os) const override;
	void cargarDesdeBinario(ifstream& is) override;
	void escribirenTexto(ofstream& os) const override;

};

#endif
