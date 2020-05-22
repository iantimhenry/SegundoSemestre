#include <iostream>
#include<string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"
#include "BaseDeDatos.h"

int main() {
  Cuenta c("Javier", 34, , 10000, 00001);
  CuentaAhorro ca("Natalia", 27, 15000, 00002, 0.05, 5000);
  CuentaCredito cc("Gustavo", 40, 30000, 00003, 10000);
  BaseDeDatos bd();

  bd.agregaCuenta(c);
  bd.agregaCuentaAhorro(ca);
  bd.agregaCuentaCredito(ca);
  
  bd.mostrarLista();

  
  return 0
}