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

#include <cstdlib>
#include <string>
#include <iostream>
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
		string e;
		while((i<MAX_CLASES)&&(sistemaClase[i]!=NULL)){
			if (sistemaClase[i]->getId()==clase.getId()){
				throw(true);
			}
                        i++;
		}
		if (i<MAX_CLASES){
                        Clase * clase_base;
                        clase_base = clase.crearClase();
                        Entrenamiento *entrena = dynamic_cast<Entrenamiento*> (clase_base);
			if (entrena != NULL) {
                                sistemaClase[i] = entrena;
			} 
                        else {
                                Spinning *spin = dynamic_cast<Spinning*> (clase_base);
				sistemaClase[i] = spin;
			}
		}
	}
	catch (bool e){
		cout<< "invalid_argument"<< endl;
	}
};

void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){
	int i=0;
	while ((i<MAX_CLASES) && (sistemaClase[i]->getId()!=idClase)){
		i++;
	}
	int j=0;
	while((i<MAX_SOCIOS)&&(sistemaSocio[i]->getCI()!=ciSocio)){
		j++;
	}
	try{
		if (!(sistemaClase[i]->agregarInsc(ciSocio,sistemaSocio[j],fecha))){
			throw(true);
		}
	}
	catch(bool e){
		cout<< "invalid_argument"<< endl;
	}
}

void borrarInscripcion(string ciSocio, int idClase) {
        int i=0;
	while ((i<MAX_CLASES) && (sistemaClase[i]->getId()!=idClase)) {
		i++;
	}
        try {
                if (!(sistemaClase[i]->borrarInsc(ciSocio))) {
                        throw(true);
                }
        }
        catch (bool e) {
                cout << "invalid_argument" << endl;
        }
}

DtSocio** obtenerInfoSociosPorClase(int idClase, int& cantSocios) {
        int i=0;
	while ((i<MAX_CLASES) && (sistemaClase[i]->getId()!=idClase)) {
		i++;
	}
        return sistemaClase[i]->obtenerInfoSocios(cantSocios);
}	

		
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