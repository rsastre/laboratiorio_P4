#ifndef _CLASE_HPP
#define _CLASE_HPP

#include "../include/Turno.hpp"
#include "../include/Inscripcion.hpp"
#include "../include/Fecha.hpp"
#include "../include/DtSocio.hpp"
#include "../include/Socio.hpp"

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
