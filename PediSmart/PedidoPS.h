#pragma once
#ifndef PEDIDO_PS_H
#define PEDIDO_PS_H

#include "ClientePS.h"
#include <vector>
#include <memory>
#include <string>
#include "ProductosPS.h"

using namespace std;




class PedidoPS {
private:
    int id;
    shared_ptr<ClientePS> cliente;
    vector<shared_ptr<ProductosPS>> productos;
    double descuento;

public:
    PedidoPS(int id, shared_ptr<ClientePS> cliente);

    int getId() const;
    shared_ptr<ClientePS> getCliente() const;
    const vector<shared_ptr<ProductosPS>>& getProductos() const;
    double getDescuento() const;

    void agregarProducto(shared_ptr<ProductosPS> producto);
    double calcularTotal() const;
    void aplicarDescuento(double porcentaje);

    string toString() const;
	void limpiarProductos();
};

#endif
