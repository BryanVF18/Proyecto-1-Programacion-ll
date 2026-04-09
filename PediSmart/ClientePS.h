#pragma once
#ifndef CLIENTE_PS_H
#define CLIENTE_PS_H

#include <string>

using namespace std;



class ClientePS {
private:
	int id;
	string name;
	string telefono;

public:
	ClientePS(int id, const string& name, const string& telefono);
	int getId() const;
	string getName() const;
	string getTelefono() const;
	void setName(const string& name);
	void setTelefono(const string& telfono);
	string toString() const;
};

#endif