#ifndef PAGO_PS_H
#define PAGO_PS_H

#include "MetodoPagoPS.h"
#include <string>

using namespace std;



enum class TipoPago { EFECTIVO, TARJETA, DIGITAL };

class PagoPS : public MetodoPagoPS {
private:
    TipoPago tipo;
    double montoEntregado;
    string ultimos4Digitos;
    string banco;
    string plataforma;
    string numeroContacto;

    bool procesarEfectivo(double monto);
    bool procesarTarjeta(double monto);
    bool procesarDigital(double monto);

public:
   
    explicit PagoPS(TipoPago tipo, double montoEntregado = 0.0,
        const string& ultimos4Digitos = "",
        const string& banco = "",
        const string& plataforma = "",
        const string& numeroContacto = "");

    bool procesar(double monto) override;
    double calcularCambio(double monto) const;
    string getNombre() const override;
};

#endif