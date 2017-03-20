#include "../include/Entrenamiento.hpp"
#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"

#include <cstdlib>
#include <string>

using namespace std;

Entrenamiento::Entrenamiento(int unid, string unnombre, Turno unturno, bool rambla) : Clase(unid, unnombre, unturno) {
        this->enRambla = rambla;
}

int Entrenamiento::cupo() {
	int res;
	if (this->enRambla)
		res = 20;
	else
		res = 10;
	return res;
}

