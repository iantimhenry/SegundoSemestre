#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

#include <iostream>
#include<string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"

class BaseDeDatos{
  private:
    Cuenta cuentas[100];
    CuentaAhorro cuentasAhorro[100];
    CuentaCredito cuentasCredito[100];
    int tempC;
    int tempCA;
    int tempCC;
  public:
    BaseDeDatos();
    agregaCuenta(Cuenta);
    agregaCuentaAhorro(CuentaAhorro);
    agregaCuentaCredito(CuentaCredito);
    eliminaCuenta(Cuenta);
    eliminaCuentaAhorro(CuentaAhorro);
    eliminaCuentaCredito(CuentaCredito);
    mostrarLista();

};

BaseDeDatos::BaseDeDatos(){
  tempC = 0;
  tempCA = 0;
  tempCC = 0;
}

void BaseDeDatos::agregaCuenta(Cuenta c){
  cuentas[tempC] = c;
  tempC++;
}

void BaseDeDatos::agregaCuentaAhorro(CuentaAhorro ca){
  cuentasAhorro[tempCA] = ca;
  tempCA++;
}

void BaseDeDatos::agregaCuentaCredito(CuentaCredito cc){
  cuentasCredito[tempCC] = cc;
  tempCC++;
}

void BaseDeDatos::eliminaCuenta(Cuenta c){
  cuentas[tempC-1] = 0;
  tempC--;
}

void BaseDeDatos::eliminaCuentaAhorro(CuentaAhorro ca){

}

void BaseDeDatos::eliminaCuentaCredito(CuentaCredito cc){

}

void BaseDeDatos::mostrarLista(){
  cout << "Cuentas básicas" << endl;
  for (i=0, i<=tempC, i++){
    cout << "Nombre del cliente: " << cuentas[i].getNombre << endl;
    cout << "Número de cuenta: " << cuentas[i].getNoCuenta << endl;
    cout << endl;
  }
  cout << "Cuentas de Ahorro" << endl;
  for (i=0, i<=tempCA, i++){
    cout << "Nombre del cliente: " << cuentasAhorro[i].getNombre << endl;
    cout << "Número de cuenta: " << cuentasAhorro[i].getNoCuenta << endl;
    cout << "Tasa de Interés: " << cuentasAhorro[i].getInteres << endl;
    cout << "Saldo mínimo: $" << cuentasAhorro[i].getSaldoMinimo << endl;
    cout << endl;
  }
  cout << "Cuentas de Credito" << endl;
  for (i=0, i<=tempCA, i++){
    cout << "Nombre del cliente: " << cuentasCredito[i].getNombre << endl;
    cout << "Número de cuenta: " << cuentasCredito[i].getNoCuenta << endl;
    cout << "Crédito: $" << cuentasCredito[i].getLimCredito << endl;
    cout << endl;
  }
}

#endif