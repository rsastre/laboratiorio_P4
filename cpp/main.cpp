#include "../include/Clase.hpp"
#include "../include/DtClase.hpp"
#include "../include/DtEntrenamiento.hpp"
#include "../include/DtSocio.hpp"
#include "../include/DtSpinning.hpp"
#include "../include/Entrenamiento.hpp"
#include "../include/Fecha.hpp"
#include "../include/Inscripcion.hpp"
#include "../include/Socio.hpp"
#include "../include/Spinning.hpp"
#include "../include/Turno.hpp"

#include <string>
#include <cstdlib>

using namespace std;

const int MAX_SOCIOS= 100;
const int MAX_CLASES= 100;

Socio *sistemaSocio[MAX_SOCIOS];
Clase *sistemaClase[MAX_CLASES];

void agregarSocio(string ci, string nombre){
	try{
		int i=0;
		while((i<MAX_SOCIOS)&&(sistemaSocio[i]!=NULL)){
			if (sistemaSocio[i]->getCI()==ci){
				throw (true);
			}
		i++;
		}
		if (i<MAX_SOCIOS){
			sistemaSocio[i]= new Socio(ci,nombre);
		}
	}
	catch (bool e){
		cout<<"invalid_argument"<< endl;
	}
};

void agregarClase(DtClase& clase){
	try{
		int i=0;
		while((i<MAX_CLASES)&&(sistemaClase[i]!=NULL)){
			if (sistemaClase[i]->getId()==clase.getId()){
				throw(true);
			}
		i++;
		}
		if (i<MAX_CLASES){
                        DtClase * ptr_clase;
                        ptr_clase = &clase;
                        DtEntrenamiento *entrena = static_cast<DtEntrenamiento*>(ptr_clase);
                        if (entrena != NULL) {
				int id=entrena->getId();
				string nombre=entrena->getNombre();
				Turno turno=entrena->getTurno();
                                bool rambla=entrena->getEnRambla();
				sistemaClase[i]=new Entrenamiento(id,nombre,turno,rambla);
			}else{
                                DtSpinning *spin = static_cast<DtSpinning*>(ptr_clase);
				int id=spin->getId();
				string nombre=spin->getNombre();
				Turno turno=spin->getTurno();
				int cantBicicletas=spin->getCantBicicletas();
				sistemaClase[i]=new Spinning(id,nombre,turno,cantBicicletas);
			}
		}
	}
	catch (bool e){
		cout<< "invalid_argument"<< endl;
	}
};


	

		
int main()
{ 
	for(int i=0; i<MAX_SOCIOS; i++){
		sistemaSocio[i]=NULL;
	}
	for (int i = 0; i < MAX_CLASES; i++){
		sistemaClase[i]=NULL;
	}


	return 0;
}