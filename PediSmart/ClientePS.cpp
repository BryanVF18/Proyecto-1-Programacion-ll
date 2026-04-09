#include "ClientePS.h"


using namespace std;



ClientePS::ClientePS(int id, const string& name, const string& telefono)
    : id(id), name(name), telefono(telefono) {
}

int ClientePS::getId() const {
    return id;
}

string ClientePS::getName() const {
    return name;
}

string ClientePS::getTelefono() const {
    return telefono;
}

void ClientePS::setName(const string& name) {
    this->name = name;
}

void ClientePS::setTelefono(const string& telefono) {
    this->telefono = telefono;
}

string ClientePS::toString() const {
    return "Cliente #" + to_string(id) + " | " + name + " | Tel: " + telefono;
}