#include <string>
#include "Turno.hpp"
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
    
};
    
    
    
