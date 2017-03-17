
#ifndef _INSCRIPCION_HPP
#define _INSCRIPCION_HPP


#include "Fecha.hpp"
#include "Socio.hpp"

class Inscripcion 
{
private:
    Fecha f;
    Socio S;
public:
    Inscripcion(Fecha,Socio);
    Fecha getfecha();
    Socio getSocio();
};

#endif
