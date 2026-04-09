#ifndef BEBIDA_PS_H
#define BEBIDA_PS_H

#include "ProductosPS.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



class BebidaPS : public ProductosPS {
private:
    bool alcoholica;

public:
    BebidaPS(const string& nombre, double precioBase, bool alcoholica);

    bool getAlcoholica() const;
    double getPrecio() const override;
    string getDescripcion() const override;
	void escribirenbinario(ofstream& os) const override;
	void cargarDesdeBinario(ifstream& is) override;
	void escribirenTexto(ofstream& os) const override;

};

#endif