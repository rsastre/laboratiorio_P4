#include "../include/DtEntrenamiento.hpp"
#include "../include/Entrenamiento.hpp"

void DtEntrenamiento::setEnRambla(bool n){
    this->enRambla=n;
}

bool DtEntrenamiento::getEnRambla(){
    return this->enRambla;
}

Entrenamiento *DtEntrenamiento::crearClase() {
        Entrenamiento *res = new Entrenamiento(this->getId(), this->getNombre(), this->getTurno(), this->enRambla);
        return res;
}
