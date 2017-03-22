#include "../include/DtSpinning.hpp"
#include "../include/Spinning.hpp"
<<<<<<< HEAD
#include "../include/Turno.hpp"
#include "../include/DtClase.hpp"
=======
>>>>>>> efca221aded49ecde1b90f0d9b3c0bd8a268cb1f

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

Spinning * DtSpinning::crearClase() {
        Spinning *res = new Spinning(this->getId(), this->getNombre(), this->getTurno(), this->cantBicicletas);
        return res;
}
