#include "../include/DtSpinning.hpp"
#include "../include/Spinning.hpp"

void DtSpinning::setCantBicicletas(int n){
    this->cantBicicletas=n;
}

int DtSpinning::getCantBicicletas(){
    return this->cantBicicletas;
}

Spinning * DtSpinning::crearClase() {
        Spinning *res = new Spinning(this->getId(), this->getNombre(), this->getTurno(), this->cantBicicletas);
        return res;
}
