#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>
using namespace std;

class Cliente{ // Creamos la cuenta cliente 
  private:
    string nombre;
  public:
    Cliente(); // Constructor default
    Cliente(string); // Constructor con sobrecarga
    void setNombre(string);
    string getNombre();
};

Cliente::Cliente(){
}

Cliente::Cliente(string _nombre){
  nombre = _nombre;
}

void Cliente::setNombre(string _nombre){
  nombre = _nombre;
}

string Cliente::getNombre(){
  return nombre;
}

#endif