#ifndef _DTSPINNING_HPP
#define _DTSPINNING_HPP

#include "DtClase.hpp"


class DtSpinning: public DtClase {
private:
    int cantBicicletas;
public:
    void setCantBicicletas(int n);
    int getCantBicicletas();
};

#endif
