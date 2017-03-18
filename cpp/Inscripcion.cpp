#include "../include/Fecha.hpp"
#include "../include/Inscripcion.hpp"
Inscripcion::Inscripcion(Fecha unfecha,Socio *unsocio){
    this->f=unfecha;
    this->s=unsocio;
}
Fecha Inscripcion:: getfecha(){
    return this->f;
}
Socio * Inscripcion:: getSocio(){
    return this->s;
}
