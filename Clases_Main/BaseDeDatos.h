#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"

class BaseDeDatos{ // Creamos la clase Base de Datos 
  private:
    int tempC;
  public:
    Cuenta *cuentas[100]; // ¿Agregación? ¿Polimorfismo?
    BaseDeDatos(); // Constructor default
    void mostrarLista();
};

BaseDeDatos::BaseDeDatos(){
  tempC = 0;
}


/*
void BaseDeDatos::mostrarLista(){
  for (int i=0; i<100; i++){
    Cuenta *actual = cuentas[i];
    cout << actual->mostrarCuenta();
  }
}
*/

#endif