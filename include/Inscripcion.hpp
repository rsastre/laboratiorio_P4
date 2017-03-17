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
