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

int Clase::cupo() = 0;

void agregarInscripcion(string ciSocio, int idClase, Fecha fecha) {
	bool cancelar_inscripcion = false;
	int i = 0;
	while ((i < cant_inscriptos) && !cancelar_inscripcion) {
		if (this->inscriptos.id_socio() == ciSocio)
			cancelar_inscripcion = true;
		i++;
	}
	if (cant_inscriptos >= this.cupo()) {
		cancelar_inscripcion = true;
	}
	if (!cancelar_inscripcion) {
		this->inscriptos = new Inscripcion(fecha, ciSocio);
		this->cant_inscriptos++;
	}
}
