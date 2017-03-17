#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"

#include <cstdlib>
#include <string>

using namespace std;

Spinning::Spinning(int unid, string unnombre, Turno unturno, int cantBicicletas) {
	this->id = unid;
	this->nombre = unnombre;
	this->turno = unturno;
	this->inscriptos = new ptr_inscripcion[50];
	for (int i = 0; i < 50; i++)
		this->inscriptos[i] = NULL;
	this->cant_inscriptos = 0;
	this->cantBicicletas = cantBicicletas;
}

int Clase::cupo() {
	return cantBicicletas;
}
