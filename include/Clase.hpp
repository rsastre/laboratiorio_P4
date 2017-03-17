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
		int virtual cupo();
		
		//setters
//		void setId();
//		void setNombre();
//		void setTurno();
		void agregarInscripcion(string ciSocio, int idClase, Fecha fecha);
};
