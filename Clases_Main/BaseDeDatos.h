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
    Cuenta *cuentas[100];
  public:
    BaseDeDatos(); // Constructor default
    void agregaAhorro(string, float, int, float, float);
    void agregaCredito(string, float, int, float);
    void mostrarLista();
    Cuenta* seleccionarCuenta(int);
    void eliminaCuenta(int);
};

BaseDeDatos::BaseDeDatos(){
  tempC = 0;
}

void BaseDeDatos::agregaAhorro(string nombre, float saldo, int noCuenta, float interes, float saldoMinimo){ 
  cuentas[tempC] = new CuentaAhorro(nombre, saldo, noCuenta, interes, saldoMinimo);
  tempC++;

}

void BaseDeDatos::agregaCredito(string nombre, float saldo, int noCuenta, float credito){
  cuentas[tempC] = new CuentaCredito(nombre, saldo, noCuenta, credito);
  tempC++;
}

void BaseDeDatos::mostrarLista(){
  for (int i=0; i<tempC; i++){
    cuentas[i]->mostrarCuenta();
  }
}

//Dudas
Cuenta* BaseDeDatos::seleccionarCuenta(int _noCuenta){
  for (int i=0; i<tempC; i++){
    Cuenta *actual = cuentas[i];
    if (actual->getNoCuenta() == _noCuenta){
      return actual;
    }
  }
}


void BaseDeDatos::eliminaCuenta(int cuenta){
  for(int i=0; i<tempC; i++){
    Cuenta *actual = cuentas[i];
    if (actual->getNoCuenta() == cuenta){
      delete cuentas[i];
    }
  }
}


#endif