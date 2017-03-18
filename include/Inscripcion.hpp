
#ifndef _INSCRIPCION_HPP
#define _INSCRIPCION_HPP


#include "Fecha.hpp"
#include "Socio.hpp"

class Inscripcion 
{
private:
    Fecha f;
    Socio *s;
public:
    Inscripcion(Fecha unfecha,Socio *unsocio);
    Fecha getfecha();
    Socio *getSocio();
};

#endif
