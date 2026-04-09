#ifndef PERSONALIZACION_PS_H
#define PERSONALIZACION_PS_H

#include "DecoradorOrdenPS.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;



class PersonalizacionPS : public DecoradorOrdenPS {
private:
    vector<pair<string, double>> ingredientesExtra;
    vector<string> ingredientesRemovidos;
    string tamanio;
    double factorPrecio;

public:
    explicit PersonalizacionPS(unique_ptr<ProductosPS> producto);

    void agregarIngrediente(const string& ingrediente, double costo);
    void quitarIngrediente(const string& ingrediente);
    void cambiarTamanio(const string& tamanio, double factor);

    double getPrecio() const override;
    string getDescripcion() const override;
};

#endif