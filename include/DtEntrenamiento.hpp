#ifndef _DTENTRENAMIENTO_HPP
#define _DTENTRENAMIENTO_HPP

#include "DtClase.hpp"


class DtEntrenamiento: public DtClase {
private:
    bool enRambla;
public:
    void setEnRambla(bool n);
    bool getEnRambla();
};

#endif
