#ifndef _DTENTRENAMIENTO_HPP
#define _DTENTRENAMIENTO_HPP

#include "DtClase.hpp"
#include "Entrenamiento.hpp"

class DtEntrenamiento: public DtClase {
private:
    bool enRambla;
public:
    void setEnRambla(bool n);
    bool getEnRambla();
    virtual Entrenamiento * crearClase();
};

#endif
