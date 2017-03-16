#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"

#include <stdlib>
#include <string>

using namespace std;

Spinning::Spinning(int unid, string unnombre, Turno unturno, bool rambla) {
	this->id = unid;
	this->nombre = unnombre;
	this->turno = unturno;
	this->inscriptos = new ptr_inscripcion[50];
	for (int i = 0; i < 50; i++)
		this->inscriptos[i] = NULL;
	this->cant_inscriptos = 0;
	this->enRambla = rambla;
}

int Clase::cupo() {
	int res;
	if (this->enRambla)
		res = 20;
	else
		res = 10;
	return res;
}
