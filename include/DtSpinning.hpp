#ifndef _DTSPINNING_HPP
#define _DTSPINNING_HPP

#include "DtClase.hpp"
#include "Spinning.hpp"


class DtSpinning: public DtClase {
protected:
    int cantBicicletas;
public:
	Spinning CrearClase(DtClase clase);
    void setCantBicicletas(int n);
    int getCantBicicletas();
    virtual Spinning * crearClase();
};

#endif
