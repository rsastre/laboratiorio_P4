#ifndef _DTSOCIO_HPP
#define _DTSOCIO_HPP

#include<string>
using namespace std;

class DtSocio {
private: 
    int CI;
    string nombre;
public:
    int getCI();
    string getNombre();
    void setCI(int ci);
    void setNombre(string nombre);
};

#endif
