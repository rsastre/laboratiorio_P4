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
			if((dynamic_cast<DtEntrenamiento&>(clase))!=NULL){
				int id=clase.getId();
				string nombre=clase.getNombre();
				Turno turno=clase.getTurno();
				DtEntrenamiento *entrena;
				entrena=dynamic_cast<DtEntrenamiento*>(clase);
				bool rambla=entrena->getEnRampla();
				sistemaClase[i]=new Entrenamiento(id,nombre,turno,rambla);
			}else{
				int id=clase.getId();
				string nombre=clase.getNombre();
				Turno turno=clase.getTurno();
				bool cantBicicletas=clase.getCantBicicletas();
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