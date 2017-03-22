#ifndef _CLASE_HPP
#define _CLASE_HPP

<<<<<<< HEAD
#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"
#include "../include/Fecha.hpp"
#include "../include/DtSocio.hpp"
#include "../include/Socio.hpp"
=======
#include "Turno.hpp"
#include "Inscripcion.hpp"
#include "Fecha.hpp"
#include "DtSocio.hpp"
>>>>>>> efca221aded49ecde1b90f0d9b3c0bd8a268cb1f

#include <string>

using namespace std;

class Clase {
	protected:
		int id;
		string nombre;
		Turno turno;
		typedef Inscripcion *ptr_inscripcion;
		ptr_inscripcion *inscriptos;
		int cant_inscriptos;

	public:
		//constuctores
		Clase(int unid, string unnombre, Turno unturno);
		
		//getters
		int getId();
		string getNombre();
		Turno getTurno();
		virtual int cupo() = 0;
                DtSocio** obtenerInfoSocios(int cantSocios);
		
		//setters
		bool agregarInsc(string ciSocio, Socio *nuevo, Fecha fecha);
                
                bool borrarInsc(string ciSocio);
};

#endif
