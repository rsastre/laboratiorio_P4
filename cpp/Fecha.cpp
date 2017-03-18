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
    try{
    if ((dia>31)||(dia<1)){
        throw dia;
    }else{
        this->dia=dia;
        }
    }
    catch(int e) {
        cout <<"invalid_argument" << endl;
    }
}

void Fecha::setmes(int mes){
    try{
    if ((mes<1)||(mes>12)){
        throw mes;
    }else{
        this->mes=mes;
        }
    }
    catch(int e){
        cout<<"invalid_argument" << endl;
    }
}
void Fecha::setanio(int anio){
    try{
    if (anio<1900){
        throw anio;
    }else{
        this->anio=anio;
        }
    }      
    catch (int e){
        cout<<"invalid_argument"<< endl;
    }
}

        
