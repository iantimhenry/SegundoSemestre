#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

#include <iostream>
#include<string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"

class BaseDeDatos{ // Creamos la clase Base de Datos 
  private:
    Cuenta cuentas[100];
    int tempC;
  public:
    BaseDeDatos(); // Constructor default
    void agregaCuenta(Cuenta);
    void eliminaCuenta(Cuenta);
    void mostrarLista();
};

BaseDeDatos::BaseDeDatos(){
  tempC = 0;
}

void BaseDeDatos::agregaCuenta(Cuenta c){
  cuentas[tempC] = c;
  tempC++;
}

void BaseDeDatos::agregaCuenta(CuentaAhorro ca){
  cuentas[tempC] = ca;
  tempC++;
}

void BaseDeDatos::agregaCuenta(CuentaCredito cc){
  cuentas[tempC] = cc;
  tempC++;
}

void BaseDeDatos::eliminaCuenta(Cuenta c){
  for(int i=0, i<=tempC, i++){
    if (c.getNoCuenta == cuentas[i].getNoCuenta){
      delete c;
    }
      
  }
}

void BaseDeDatos::mostrarLista(){
  cout << "Cuentas básicas" << endl;
  for (int i=0, i<=tempC, i++){
    cout << "Nombre del cliente: " << cuentas[i].getNombre << endl;
    cout << "Número de cuenta: " << cuentas[i].getNoCuenta << endl;
    cout << endl;
  }
  cout << "Cuentas de Ahorro" << endl;
  for (int i=0, i<=tempCA, i++){
    cout << "Nombre del cliente: " << cuentasAhorro[i].getNombre << endl;
    cout << "Número de cuenta: " << cuentasAhorro[i].getNoCuenta << endl;
    cout << "Tasa de Interés: " << cuentasAhorro[i].getInteres << endl;
    cout << "Saldo mínimo: $" << cuentasAhorro[i].getSaldoMinimo << endl;
    cout << endl;
  }
  cout << "Cuentas de Credito" << endl;
  for (int i=0, i<=tempCA, i++){
    cout << "Nombre del cliente: " << cuentasCredito[i].getNombre << endl;
    cout << "Número de cuenta: " << cuentasCredito[i].getNoCuenta << endl;
    cout << "Crédito: $" << cuentasCredito[i].getLimCredito << endl;
    cout << endl;
  }
}

#endif