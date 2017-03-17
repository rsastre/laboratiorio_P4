#ifndef _ENTRENAMIENTO_HPP
#define _ENTRENAMIENTO_HPP

#include "Clase.hpp"
#include "Turno.hpp"
#include "Inscripcion.hpp"

#include <string>

using namespace std;

class Entrenamiento: public Clase {
	private:
		bool enRambla;

	public:
		Spinning(int unid, string unnombre, Turno unturno, bool enRambla);
		int virtual cupo();
};

#endif
