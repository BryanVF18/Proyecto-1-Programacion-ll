#ifndef GESTORARCHIVOSPS_H
#define GESTORARCHIVOSPS_H
#pragma once

#include <string>
#include "PedidoPS.h" 
#include <map>
#include <functional>

using namespace std;
class GestorArchivosPS
{
public: 
	static void guardarPedidoBinario(const PedidoPS& pedido, const string& id);
	static void cargarPedidoBinario(PedidoPS& pedido, const string& id);
;
};

#endif