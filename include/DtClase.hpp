#ifndef _DTCLASE_HPP
#define _DTCLASE_HPP

#include "Turno.hpp"
#include "Clase.hpp"
#include "Entrenamiento.hpp"

#include <string>

using namespace std;


class DtClase {

private:
    int id;
    string nombre;
    Turno turno;

public:
    int getId();
    string getNombre();
    Turno getTurno();
    void setId(int id);
    void setNombre(string nombre);
    void setTurno(Turno turno);
    virtual Clase * crearClase();
};

#endif
