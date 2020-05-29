/*
Ian Timothy Henry Suárez
A01701578
*/

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"
#include "BaseDeDatos.h"

int main(){

  BaseDeDatos bd;

  bd.cuentas[0] = new Cuenta("Javier", 10000, 00001);
  bd.cuentas[1] = new CuentaAhorro("Natalia", 15000, 00002, 0.05, 5000);
  bd.cuentas[3] = new CuentaCredito("Gustavo", 30000, 00003, 10000);
  
  //bd.mostrarLista();

  for (int i=0; i<10; i++){
    cout << bd.cuentas[i] -> mostrarCuenta();
  }

  return 0;
}