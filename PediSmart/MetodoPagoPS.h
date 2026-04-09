#ifndef METODOPAGO_PS_H
#define METODOPAGO_PS_H

#include <string>

using namespace std;



class MetodoPagoPS {
public:
    virtual ~MetodoPagoPS() = default;

    virtual bool procesar(double monto) = 0;
    virtual string getNombre() const = 0;
};

#endif
