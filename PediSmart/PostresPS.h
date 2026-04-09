#ifndef POSTRES_PS_H
#define POSTRES_PS_H

#include "ProductosPS.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



class PostresPS : public ProductosPS {
private:
    bool vegano;

public:
    PostresPS(const string& nombre, double precioBase, bool vegano);
    bool getVegano() const;
    double getPrecio() const override;
    string getDescripcion() const override;
	void escribirenbinario(ofstream& os) const override;
	void cargarDesdeBinario(ifstream& is) override;
	void escribirenTexto(ofstream& os) const override;

};

#endif