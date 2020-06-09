/*
Proyecto Segundo Semestre
Ian Timothy Henry Suárez
A01701578
*/

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>
using namespace std;

class Cliente{ // Creamos la cuenta cliente 
  
  private: //Atributos
    string nombre;
  
  public: //Métodos
    Cliente(); // Constructor default
    Cliente(string); // Constructor con sobrecarga
    void setNombre(string);
    string getNombre();
};

Cliente::Cliente(){
}

Cliente::Cliente(string t_nombre){
  nombre = t_nombre;
}

/*
Métodos de acceso
*/
void Cliente::setNombre(string t_nombre){
  nombre = t_nombre;
}

string Cliente::getNombre(){
  return nombre;
}

#endif