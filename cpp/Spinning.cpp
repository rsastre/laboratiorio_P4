#include "../include/Spinning.hpp"
#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"

#include <cstdlib>
#include <string>

using namespace std;

Spinning::Spinning(int unid, string unnombre, Turno unturno, int cantBicicletas) : Clase(unid, unnombre, unturno) {
	this->cantBicicletas = cantBicicletas;
}

int Spinning::cupo() {
	return this->cantBicicletas;
}
