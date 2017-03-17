#include "../include/Fecha.hpp"
#include <iostream>
#include <string>
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
    if ((dia<=31)&&(dia>=1)){
        this->dia=dia;
    }else{
        cout<<"invalid_argument";
    };
}
void Fecha::setmes(int mes){
    if ((mes>=1)&&(mes<=12)){
        this->mes=mes;
    }else{
        cout<<"invalid_argument";
    };
}
void Fecha::setanio(int anio){
    if (anio>=1900){
        this->anio=anio;
    }else{
        cout<<"invalid_argument";
    };
}

        
