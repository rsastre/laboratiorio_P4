#ifndef _SOCIO_HPP
#define _SOCIO_HPP

#include <string>
#include <iostream>
using namespace std;
class Socio {
private:
    string CI;
    string nombre;
public:
    //using namespace std;

    Socio(string,string);
    string getCI();
    string getnombre();
    };
    
#endif
