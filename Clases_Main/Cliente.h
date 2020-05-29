#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>
using namespace std;

class Cliente{ // Creamos la cuenta cliente 
  private:
    string nombre;
    int edad;
  public:
    Cliente(); // Constructor default
    Cliente(string, int); // Constructor con sobrecarga
    void setNombre(string);
    void setEdad(int);
    string getNombre();
    int getEdad();
};

Cliente::Cliente(){
}

Cliente::Cliente(string _nombre, int _edad){
  nombre = _nombre;
  edad = _edad;
}

void Cliente::setNombre(string _nombre){
  nombre = _nombre;
}

void Cliente::setEdad(int _edad){
  edad = _edad;
}

string Cliente::getNombre(){
  return nombre;
}

int Cliente::getEdad(){
  return edad;
}

#endif