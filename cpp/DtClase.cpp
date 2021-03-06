#include "../include/DtClase.hpp"
#include "../include/Clase.hpp"
#include "../include/Turno.hpp"
#include "../include/Entrenamiento.hpp"

#include <string>

using namespace std;

int DtClase::getId(){
    return this->id;
}
string DtClase::getNombre(){
    return this->nombre;
}

Turno DtClase::getTurno(){
    return this->turno;
}

void DtClase::setId(int id){
    this->id=id;
}
 void DtClase::setNombre(string nombre){
     this->nombre=nombre;
 }

void DtClase::setTurno(Turno turno){
    this->turno=turno;
}

Clase * DtClase::crearClase() {
        Entrenamiento *res = new Entrenamiento(this->id, this->nombre, this->turno, false);
        return res;
}

