#include "DtSocio.hpp"
#include <string>
using namespace std;

int DtSocio::getCI(){
    return this->CI;
}
string DtSocio::getNombre(){
    return this->nombre;
}
 void DtSocio::setCI(int ci){
     this->CI=ci;
 }
 
void DtSocio::setNombre(string nombre){
    this->nombre=nombre;
}
