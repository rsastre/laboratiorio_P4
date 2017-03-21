#include "../include/Fecha.hpp"
#include <iostream>
#include <string>
#include <exception>
using namespace std; 

int Fecha::getdia(){
    return this->dia;
}
int Fecha::getmes(){
    return this->mes;
}
int Fecha::getanio(){
    return this->anio;
}

void Fecha::setdia(int dia){
    try{
    if ((dia>31)||(dia<1)){
        throw std::invalid_argument("dia erróneo");
    }else{
        this->dia=dia;
        }
    }
    catch(const std::invalid_argument& ia) {
        cout <<"El dia ingresado debe ser entre el rango 1..31\n";
    }
}

void Fecha::setmes(int mes){
    try{
    if ((mes<1)||(mes>12)){
        throw std::invalid_argument("mes erróneo");
    }else{
        this->mes=mes;
        }
    }
    catch (const std::invalid_argument& ia){
        cout<< "El mes ingresado debe ser entre el rango 1..12\n"; 
    }
}
void Fecha::setanio(int anio){
    try{
    if (anio<1900){
        throw std::invalid_argument("año erróneo");
    }else{
        this->anio=anio;
        }
    }      
    catch (const std::invalid_argument& ia){
        cout<<"El año ingresado debe ser mayor o igual a 1900\n";
    }
}

        
