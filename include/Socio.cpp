#include "Socio.hpp"
#include <string>
using namespace std;

string Socio::getCI(){
    return this->CI;
}
string Socio::getnombre(){
    return this->nombre;
}
Socio::Socio(string unCI,string unnombre){
this->CI=unCI;
this->nombre=unnombre;
}
    
