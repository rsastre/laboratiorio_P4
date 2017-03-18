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
	int i=0;
	bool sigobuscando=true;
	while ((i<MAX_SOCIOS) && (sigobuscando)){
		if (sistemaSocio[i]!=NULL){
			if (sistemaSocio[i]->getCI()==ci){
				sigobuscando==false;
			}
		}
	i++;
	}
	if (sigobuscando==true){
		sistemaSocio[i]=new Socio(ci,nombre);
	}else{
		tirar exepcion std::invalid argument
	}
}

void agregarClase(DtClase& clase){
	Spinning spinning


}
	

		
int main()
{ 
	for(int i=0; i<MAX_SOCIOS; i++){
		sistemaSocio[i]=NULL;
	}
	for (int i = 0; i < MAX_CLASES; i++){
		sistemaClase[i]=NULL
	}
















	return 0;
}