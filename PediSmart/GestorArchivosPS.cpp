#include "GestorArchivosPS.h"
#include <fstream>
#include <iostream>
#include "ComidaPS.h"
#include "BebidaPS.h"
#include "PostresPS.h"
#include "ProductosPS.h"
#include <map>
#include <functional>

// Mapeo para crear productos según su tipo
namespace {
    std::map<int, std::function<std::shared_ptr<ProductosPS>()>> mapaProductos = {
        {1, []() { return std::make_shared<ComidaPS>("",0,""); }},
        {2, []() { return std::make_shared<BebidaPS>("",0,false); }},
        {3, []() { return std::make_shared<PostresPS>("",0,false); }}
    };
}

void GestorArchivosPS::guardarPedidoBinario(const PedidoPS& pedido, const std::string& id) {
    std::ofstream archivo(id, std::ios::binary);
    if(!archivo) return;

	const auto& productos = pedido.getProductos();
	size_t total = productos.size();
	archivo.write(reinterpret_cast<const char*>(&total), sizeof(total));
 
    for (const auto& e : productos) {
        auto base = dynamic_cast<ProductosPS*>(e.get());
        if (base) {
            base->escribirenbinario(archivo);
        }
    }
}


void GestorArchivosPS::cargarPedidoBinario(PedidoPS& pedido, const std::string& id) {
	std::ifstream archivo(id, std::ios::binary);
	if (!archivo) return;
	pedido.limpiarProductos();
    size_t total = 0;
	archivo.read(reinterpret_cast<char*>(&total), sizeof(total));

    for (size_t i = 0; i < total; ++i) {
        int tipo = 0;
        archivo.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
        if (!archivo)break;
        if (mapaProductos.count(tipo)) {
            auto nuevoproducto = mapaProductos[tipo]();
            nuevoproducto->cargarDesdeBinario(archivo);
            pedido.agregarProducto(nuevoproducto);
        }
        else {
            std::cerr << "Tipo de producto desconocido: " << tipo << std::endl;
            break;
        }
    }
}

    
