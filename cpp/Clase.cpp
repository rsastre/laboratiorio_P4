#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"
#include "../include/Fecha.hpp"
#include "../include/DtSocio.hpp"

#include <cstdlib>
#include <string>

using namespace std;

Clase::Clase(int unid, string unnombre, Turno unturno) {
	this->id = unid;
	this->nombre = unnombre;
	this->turno = unturno;
	this->inscriptos = new ptr_inscripcion[50];
	for (int i = 0; i < 50; i++)
		this->inscriptos[i] = NULL;
	this->cant_inscriptos = 0;
}

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
	int pos;
        int i = 0;
	if (this->cant_inscriptos >= this->cupo()) {
		cancelar_inscripcion = true;
	}
        while ((i < 50) && (!cancelar_inscripcion)) {
                if (this->inscriptos[i] == NULL) {
                        pos = i;
                } else if (this->inscriptos[i]->getSocio()->getCI() == ciSocio) {
			cancelar_inscripcion = true;
                }
                i++;
                
	}
	if (!cancelar_inscripcion) {
		this->inscriptos[pos] = new Inscripcion(fecha, nuevo);
		this->cant_inscriptos++;
	}
        return !cancelar_inscripcion;
}

bool Clase::borrarInsc(string ciSocio) {
        int i = 0;
	while ((i<50) && (this->inscriptos[i]->getSocio()->getCI()!=ciSocio)) {
		i++;
	}
        if (i>=50) {
                return false;
        }
        else{
                this->inscriptos[i]->~Inscripcion();
                this->inscriptos[i] = NULL;
                this->cant_inscriptos--;
                return true;
        }           
}

DtSocio** Clase::obtenerInfoSocios(int& cantSocios) {
        DtSocio** res = new DtSocio*[cantSocios];
        for (int j = 0; j < cantSocios; j++) {
                res[j] = NULL;
        }
        int cont = 0;
        int i = 0;
        while ((cont <= cantSocios) && (i < 50)) {
                if (this->inscriptos[i] != NULL) {
                        int ci = atoi(this->inscriptos[i]->getSocio()->getCI().c_str());
                        string nombre = this->inscriptos[i]->getSocio()->getnombre();
                        res[cont] = new DtSocio();
                        res[cont]->setCI(ci);
                        res[cont]->setNombre(nombre);
                        cont++;
                }
                i++;
        }
        return res;
}
