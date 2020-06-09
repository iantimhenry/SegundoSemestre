/*
Proyecto Segundo Semestre
Ian Timothy Henry Suárez
A01701578
*/

#ifndef CUENTAAHORRO_H_
#define CUENTAAHORRO_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"

class CuentaAhorro : public Cuenta{ // Declaramos una clase hija (CuentaAhorro)
  
  private: //Atributos
    float interes;
    float saldoMinimo;
  
  public: //Métodos
    CuentaAhorro(); // Constructor default
    CuentaAhorro(string, string, float, int, float, float); // Constructor con sobrecarga

    void mostrarCuenta(); // Sobreescritura de métodos virtual
    void retirar(float); // Sobreescritura de métodos virtual
    /*
    Métodos de acceso
    */
    void setInteres(float);
    void setSaldoMinimo(float);
    float getInteres();
    float getSaldoMinimo();
};

CuentaAhorro::CuentaAhorro(){
}

CuentaAhorro::CuentaAhorro(string t_tipo, string t_nombre, float t_saldo, int t_noCuenta, float t_interes, float t_saldoMinimo) : Cuenta(t_tipo, t_nombre, t_saldo, t_noCuenta){ // Heredamos el nombre, edad, saldo y número de cuenta de la clase padre (Cuenta)
  interes = t_interes;
  saldoMinimo = t_saldoMinimo;
}

void CuentaAhorro::mostrarCuenta(){ // Se muestra diferente que la clase CuentaCredito
  cout << "--------------------------------------" << endl;
  cout << "\nTipo de cuenta: " << tipo << endl;
  cout << "Cliente: " << cliente.getNombre() << endl;
  cout << "Saldo: " << saldo << endl;
  cout << "Código de cliente: " << noCuenta << endl;
  cout << "Tasa de interés anual: " << (interes*100) << "%" << endl;
  cout << "Saldo mínimo: " << saldoMinimo << endl;
  cout << "--------------------------------------" << endl;
}

/*
En la clase CuentaAhorro la función retirar le permite al usuario retirar dinero sin pasarse del saldo mínimo
*/
void CuentaAhorro::retirar(float cantidad){ 
  if ((saldo - cantidad) >= saldoMinimo){
    saldo = saldo - cantidad;
  }
  else {
    cout << "No es posible retirar esa cantidad, la cantidad sobrepasa el saldo mínimo necesario"<<endl;
  }
  cout << "Saldo Actual: " << saldo << endl;
}

/*
Métodos de acceso
*/
void CuentaAhorro::setInteres(float t_interes){
  interes = t_interes;
}

void CuentaAhorro::setSaldoMinimo(float t_saldoMinimo){
  saldoMinimo = t_saldoMinimo;
}

float CuentaAhorro::getInteres(){
  return interes;
}

float CuentaAhorro::getSaldoMinimo(){
  return saldoMinimo;
}

#endif