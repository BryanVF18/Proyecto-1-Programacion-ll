#ifndef DECORADORORDEN_PS_H
#define DECORADORORDEN_PS_H

#include <memory>
#include <string>
#include "ProductosPS.h"

using namespace std;



class DecoradorOrdenPS : public ProductosPS {
protected:
    unique_ptr<ProductosPS> productoEnvuelto;

public:
    explicit DecoradorOrdenPS(unique_ptr<ProductosPS> producto);
    virtual ~DecoradorOrdenPS() = default;

    double getPrecio() const override;
    string getDescripcion() const override;
};

#endif