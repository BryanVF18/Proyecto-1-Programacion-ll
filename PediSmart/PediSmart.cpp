// Proyecto Aplicacion de pedidos intelingente "PediSmart".
// Bryan Valverde Esteban Oviedo.
#include <iostream>
#include <memory>
#include <string>

#include "ProductosPS.h"
#include "ComidaPS.h"
#include "BebidaPS.h"
#include "PostresPS.h"
#include "ClientePS.h"
#include "PedidoPS.h"
#include "DecoradorOrdenPS.h"
#include "PersonalizacionPS.h"
#include "MetodoPagoPS.h"
#include "PagoPS.h"
#include "ExcepcionesPS.h"
#include "GestorArchivosPS.h"

using namespace std;

int main() {

	cout << "Hello world!" << endl;
   /* cout << "============================================" << endl;
    cout << "   Bienvenido a PediSmart                  " << endl;
    cout << "============================================" << endl;

    // --------------------------------------------------------
    // 1. Crear cliente
    // --------------------------------------------------------
    auto cliente = make_shared<ClientePS>(1, "Juan Perez", "88001234");
    cout << "\n[Cliente]\n" << cliente->toString() << endl;

    // --------------------------------------------------------
    // 2. Crear productos
    // --------------------------------------------------------
    auto comida = make_unique<ComidaPS>("Hamburguesa", 3500.0, "Plato fuerte");
    auto bebida = make_unique<BebidaPS>("Refresco", 1200.0, false);
    auto postre = make_unique<PostresPS>("Brownie", 1500.0, true);

    cout << "\n[Productos base]" << endl;
    cout << comida->getDescripcion() << endl;
    cout << bebida->getDescripcion() << endl;
    cout << postre->getDescripcion() << endl;

    // --------------------------------------------------------
    // 3. Personalizar la hamburguesa
    // --------------------------------------------------------
    auto orden = make_unique<PersonalizacionPS>(move(comida));
    orden->agregarIngrediente("Queso extra", 500.0);
    orden->quitarIngrediente("Cebolla");
    orden->cambiarTamanio("Grande", 1.3);

    cout << "\n[Producto personalizado]" << endl;
    cout << orden->getDescripcion() << endl;
    cout << "Precio: $" << orden->getPrecio() << endl;

    // --------------------------------------------------------
    // 4. Crear pedido y agregar productos
    // --------------------------------------------------------
    auto pedido = make_shared<PedidoPS>(1, cliente);
    pedido->agregarProducto(move(orden));
    pedido->agregarProducto(move(bebida));
    pedido->agregarProducto(move(postre));
    pedido->aplicarDescuento(10.0);

    cout << "\n[Pedido]" << endl;
    cout << pedido->toString() << endl;

    // --------------------------------------------------------
    // 5. Procesar pago en efectivo
    // --------------------------------------------------------
    cout << "\n[Pago]" << endl;
    auto pago = make_shared<PagoPS>(TipoPago::EFECTIVO, 10000.0);
    pago->procesar(pedido->calcularTotal());

    // --------------------------------------------------------
    // 6. Probar excepcion de pedido vacio
    // --------------------------------------------------------
    cout << "\n[Prueba excepcion pedido vacio]" << endl;
    auto pedidoVacio = make_shared<PedidoPS>(2, cliente);
    pedidoVacio->calcularTotal();

    // --------------------------------------------------------
    // 7. Probar pago insuficiente
    // --------------------------------------------------------
    cout << "\n[Prueba pago insuficiente]" << endl;
    auto pagoInsuficiente = make_shared<PagoPS>(TipoPago::EFECTIVO, 100.0);
    pagoInsuficiente->procesar(pedido->calcularTotal());

    cout << "\n============================================" << endl;
    cout << "   Prueba finalizada                        " << endl;
    cout << "============================================" << endl;*/

    return 0;
}