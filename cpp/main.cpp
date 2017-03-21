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
#include <exception>

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
				throw std::invalid_argument("Cédula inválida");
			}
		i++;
		}
		if (i<MAX_SOCIOS){
			sistemaSocio[i]= new Socio(ci,nombre);
		}
	}
	catch (const std::invalid_argument& ia){
		cout<< "La cédula ingresada ya se encuentra incripta en el sistema\n";
	}
};

void agregarClase(DtClase& clase){
	try{
		int i=0;
		string e;
		while((i<MAX_CLASES)&&(sistemaClase[i]!=NULL)){
			if (sistemaClase[i]->getId()==clase.getId()){
				throw std::invalid_argument("Clase inválida");
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
	catch (const std::invalid_argument& ia){
		cout<< "La clase ya se encuentra ingresada en el sistema\n";
	}
};

void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){
	int i=0;
	try{
	while ((i<MAX_CLASES) && (sistemaClase[i]->getId()!=idClase)){
		i++;
	}
	if (i==MAX_CLASES){
		throw std::invalid_argument("la clase no existe");
	}
	try{
		int j=0;
		while((i<MAX_SOCIOS)&&(sistemaSocio[i]->getCI()!=ciSocio)){
			j++;
		}
		if (j==MAX_SOCIOS){
			throw std::invalid_argument("el socio no existe");
		}
		try{
			if (!(sistemaClase[i]->agregarInsc(ciSocio,sistemaSocio[j],fecha))){
				throw std::invalid_argument("ya incripto");
			}
			}
			catch(const std::invalid_argument& ia){
				cout<< "El socio ya se encuentra incripto a la clase\n";
			}
		}	
		catch (const std::invalid_argument& ia){
		cout << "El socio ingresado no se encuentra en el sistema\n";
		}
	}
	catch (const std::invalid_argument& ia){
		cout << "La clase ingresada no se encuentra en el sistema\n";
	}
};

void borrarInscripcion(string ciSocio, int idClase) {
        int i=0;
	while ((i<MAX_CLASES) && (sistemaClase[i]->getId()!=idClase)) {
		i++;
	}
        try {
                if (!(sistemaClase[i]->borrarInsc(ciSocio))) {
                        throw std::invalid_argument("no exite inscripcion");
                }
        }
        catch (const std::invalid_argument& ia) {
                cout << "No exite una inscripcion de la cédula ingresada a la clase\n";
        }
};

DtSocio** obtenerInfoSociosPorClase(int idClase, int& cantSocios) {
        int i=0;
	while ((i<MAX_CLASES) && (sistemaClase[i]->getId()!=idClase)) {
		i++;
	}
        return sistemaClase[i]->obtenerInfoSocios(cantSocios);
};	

		
int main()
{ 
	for(int i=0; i<MAX_SOCIOS; i++){
		sistemaSocio[i]=NULL;
	}
	for (int i = 0; i < MAX_CLASES; i++){
		sistemaClase[i]=NULL;
	}
	bool sigo=true;
	string comando;
	cout << "Comando Operaciones\n";
	cout << "Agregar Socio--->AS\n" << "Agregar Clase--->AC\n" << "Agregar Inscripcion--->AI\n" << "Borrar Inscripcion--->BI" << "Obtener Informacion de Socios por Clase---> OISC\n";
	while (sigo){
			cout << "Ingrese comando de operacion a realizar\n"
			cin >> comando;
			if (comando.compare("AS")==0){
				cout<< "Ingrese Cédula\n";
				string ci;
				cin >> ci;
				cout<< "Ingrese nombre\n";
				string nombre;
				cin >> nombre;
				agregarSocio(ci,nombre);
			}else{
				if (comando.compare("AC")==0){
					cout<< "Ingrese ID de la clase\n";
					int id;
					cin >> id;
					cout << "Ingrese Nombre de la clase\n";
					string nombre;
					cin >> nombre;
					cout << "Ingrese turno (Manana,Tarde,Noche)\n";
					Turno turno;
					cin >> turno;
					cout << "Ingrese 1 si la clase es Spinning o 2 si la misma es Entrenamiento\n";
					int j;
					cin >> j;
					if (j==1){
						cout << "Ingrese cantidad de Bicicletas disponible\n";
						int cant;
						cin >> cant;
						DtClase *clase=new DtSpinning();
						clase.setId(id);
						clase.setNombre(nombre);
						clase.setTurno(turno);
						clase.setCantBicicletas(cant);
						agregarClase(clase);
					}else{
						cout<< "Determine si se realiza en rambla ingresando 'si' o 'no' de lo contrario\n";
						string aux;
						cin >> aux;
						DtClase *clase=new DtEntrenamiento();
						clase.setId(id);
						clase.setNombre(nombre);
						clase.setTurno(turno);
						if (aux.compare("si")==0){
							clase.setEnRampla(true);
						}else{
							clase.setEnRampla(false);
						}
					}
			}else{
					if(comando.compare("AI")==0){
						cout << "Ingrese CI del socio a inscribir\n";
						string ci;
						cin >> ci;
						cout << "Ingrese id de la clase\n";
						int id;
						cin >> id;
						cout << "Ingrese dia de la fecha\n";
						int dia;
						cin >> dia;
						cout << "Ingrese mes de la fecha (en numeros)\n";
						int mes;
						cin >> mes;
						cout << "Ingrese año de la fecha\n";
						int anio;
						cin >> anio;
						Fecha fecha;
						fecha.setdia(dia);
						fecha.setmes(mes);
						fecha.setanio(anio);
						agregarInscripcion(ci,id,fecha);
					}else{
						 	if (comando.compare("BI")==0){
						 		cout << "Ingrese CI del socio a borrar inscripcion\n";
						 		string ci;
						 		cin >> ci;
						 		cout << "Ingrese id de la clase\n";
						 		int id;
						 		cin >> id;
						 		borrarInscripcion(ci,id);
						 	}else{
						 			if (comando.compare("OISC")==0){
						 				cout << "Ingrese id de la clase\n";
						 				int id;
						 				cin >> id;
						 				cout << "Ingrese la cantidad de incriptos a obtener\n";
						 				int cant;
						 				cin >> cant;
						 				DtSocio* res= obtenerInfoSociosPorClase(id,cant);
						 				




























	return 0;
}