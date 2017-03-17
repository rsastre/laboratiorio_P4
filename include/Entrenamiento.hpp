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
		Entrenamiento(int unid, string unnombre, Turno unturno, bool enRambla);
		virtual int cupo();
};

#endif
