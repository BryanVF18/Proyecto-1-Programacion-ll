#include "PagoPS.h"
#include "ExcepcionesPS.h"
#include <iostream>

using namespace std;



PagoPS::PagoPS(TipoPago tipo, double montoEntregado,
    const string& ultimos4Digitos, const string& banco,
    const string& plataforma, const string& numeroContacto)
    : tipo(tipo), montoEntregado(montoEntregado),
    ultimos4Digitos(ultimos4Digitos), banco(banco),
    plataforma(plataforma), numeroContacto(numeroContacto) {
}

bool PagoPS::procesarEfectivo(double monto) {
    try {
        if (montoEntregado < monto)
            throw PagoInsuficienteExcep(monto - montoEntregado);
        cout << "PediSmart: Pago en efectivo exitoso. Cambio: $"
            << calcularCambio(monto) << endl;
        return true;
    }
    catch (const PagoInsuficienteExcep& e) {
        cout << e.what() << endl;
        return false;
    }
}

bool PagoPS::procesarTarjeta(double monto) {
    try {
        if (monto <= 0)
            throw EntradaInvalidaExcep("El monto debe ser mayor a 0.");
        cout << "PediSmart: Pago con tarjeta " << banco
            << " (**** " << ultimos4Digitos << ") por $"
            << monto << " exitoso." << endl;
        return true;
    }
    catch (const EntradaInvalidaExcep& e) {
        cout << e.what() << endl;
        return false;
    }
}

bool PagoPS::procesarDigital(double monto) {
    try {
        if (monto <= 0)
            throw EntradaInvalidaExcep("El monto debe ser mayor a 0.");
        cout << "PediSmart: Pago digital via " << plataforma
            << " al contacto " << numeroContacto
            << " por $" << monto << " exitoso." << endl;
        return true;
    }
    catch (const EntradaInvalidaExcep& e) {
        cout << e.what() << endl;
        return false;
    }
}

bool PagoPS::procesar(double monto) {
    switch (tipo) {
    case TipoPago::EFECTIVO: return procesarEfectivo(monto);
    case TipoPago::TARJETA:  return procesarTarjeta(monto);
    case TipoPago::DIGITAL:  return procesarDigital(monto);
    default:
        cout << "PediSmart: Metodo de pago no reconocido." << endl;
        return false;
    }
}

double PagoPS::calcularCambio(double monto) const {
    return montoEntregado - monto;
}

string PagoPS::getNombre() const {
    switch (tipo) {
    case TipoPago::EFECTIVO: return "Efectivo";
    case TipoPago::TARJETA:  return "Tarjeta " + banco + " (**** " + ultimos4Digitos + ")";
    case TipoPago::DIGITAL:  return plataforma + " (" + numeroContacto + ")";
    default:                 return "Desconocido";
    }
}