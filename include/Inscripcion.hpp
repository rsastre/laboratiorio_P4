#ifndef _INSCRIPCION_HPP
#define _INSCRIPCION_HPP

#include "Fecha.hpp"
class Inscripcion 
{
private:
    fecha f;
    Socio S;
public:
    Inscripcion::Inscripcion(fecha,Socio);
    fecha getfecha();
    Socio getSocio();
};

#endif
