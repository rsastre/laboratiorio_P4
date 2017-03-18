#ifndef _CLASE_HPP
#define _CLASE_HPP

#include "Turno.hpp"
#include "Inscripcion.hpp"
#include "Fecha.hpp"



#include <string>

using namespace std;

class Clase {
	private:
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
		
		//setters
//		void setId();
//		void setNombre();
//		void setTurno();
		void agregarInscripcion(string ciSocio, Socio *nuevo, Fecha fecha);
};

#endif

