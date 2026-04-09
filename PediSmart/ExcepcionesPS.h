#pragma once
#ifndef EXCEPCIONESPS_H
#define EXCEPCIONESPS_H
#include <string>
#include <exception>
using namespace std;

class PedidoVacioExcep : public exception {
public:
    const char* what() const noexcept override {
        return "PediSmart: El pedido no contiene productos.";
    }
};
class PagoInsuficienteExcep : public exception {
private:
    string mensaje;
public:
    explicit PagoInsuficienteExcep(double faltante)
        : mensaje("PediSmart: Pago insuficiente. Faltan $" + to_string(faltante)) {
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class ArchivoNoEncontradoExcep : public exception {
private:
    string mensaje;
public:
    explicit ArchivoNoEncontradoExcep(const string& ruta)
        : mensaje("PediSmart: No se encontro el archivo: " + ruta) {
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class EntradaInvalidaExcep : public exception {
private:
    string mensaje;
public:
    explicit EntradaInvalidaExcep(const string& detalle)
        : mensaje("PediSmart: Entrada invalida - " + detalle) {
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};





#endif