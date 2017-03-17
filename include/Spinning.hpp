#ifndef _SPINNING_HPP
#define _SPINNING_HPP

#include "Clase.hpp"
#include "Turno.hpp"
#include "Inscripcion.hpp"

#include <string>

using namespace std;

class Spinning: public Clase {
	private:
		int cantBicicletas;

	public:
		Spinning(int unid, string unnombre, Turno unturno, int cantBicicletas);
		virtual int cupo();
};

#endif
