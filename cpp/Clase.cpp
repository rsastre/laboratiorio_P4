#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"
#include "../include/Fecha.hpp"


#include <string>

using namespace std;

int Clase::getId() {
	return this->id;
}

string Clase::getNombre() {
	return this->nombre;
}

Turno Clase::getTurno() {
	return this->turno;
}

bool Clase::agregarInsc(string ciSocio, Socio *nuevo, Fecha fecha) {  //cambio a que pasen un puntero a socio//
	bool cancelar_inscripcion = false;
	int i = 0;
	if (this->cant_inscriptos >= this->cupo()) {
		cancelar_inscripcion = true;
	}
        while ((i < this->cant_inscriptos) && (!cancelar_inscripcion)) {
		if (this->inscriptos[i]->getSocio()->getCI() == ciSocio)
			cancelar_inscripcion = true;
		i++;
	}
	if (!cancelar_inscripcion) {
		this->inscriptos[i] = new Inscripcion(fecha, nuevo);
		this->cant_inscriptos++;
	}
        return !cancelar_inscripcion;
}
