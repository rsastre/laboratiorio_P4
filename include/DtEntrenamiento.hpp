#include "DtClase.hpp"


class DtEntrenamiento: public DtClase {
private:
    bool enRambla;
public:
    void setEnRambla(bool n);
    bool getEnRambla();
};
