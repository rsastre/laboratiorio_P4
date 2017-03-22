#include "../include/DtSpinning.hpp"
#include "../include/Spinning.hpp"
#include "../include/Turno.hpp"
#include "../include/DtClase.hpp"

void DtSpinning::setCantBicicletas(int n){
    this->cantBicicletas=n;
}

Spinning DtSpinning::CrearClase(DtClase clase){
	int id=clase.getId();
	string nombre=clase.getNombre();
	Turno turno=clase.getTurno();

	int cant=clase.getCantBicicletas();
	return Spinning(id,nombre,turno,cant);
}


int DtSpinning::getCantBicicletas(){
    return this->cantBicicletas;
}

