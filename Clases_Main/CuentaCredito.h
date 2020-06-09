/*
Proyecto Segundo Semestre
Ian Timothy Henry Suárez
A01701578
*/

#ifndef CUENTACREDITO_H_
#define CUENTACREDITO_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"

class CuentaCredito : public Cuenta{ // Declaramos una clase hija (CuentaCredito)
  
  private: //Atributos
    float credito;
    float limCredito;
  
  public: //Métodos
    CuentaCredito(); // Constructor default
    CuentaCredito(string, string, float, int, float); // Constructor con sobre carga

    void mostrarCuenta(); //Sobreescritura de métodos virtual
    void retirar(float); //Sobreescritura de métodos virtual
    void usarTarjeta(float); //Función exclusiva de la clase hija CuentaCredito
    void pagarTarjeta(); //Función exclusiva de la clase hija CuentaCredito
    /*
    Métodos de acceso
    */
    void setCredito(float);
    float getCredito();
    void setLimCredito(float);
    float getLimCredito();
};

CuentaCredito::CuentaCredito(){
}

CuentaCredito::CuentaCredito(string t_tipo, string t_nombre, float t_saldo, int t_noCuenta, float t_credito) : Cuenta(t_tipo, t_nombre, t_saldo, t_noCuenta){ // Heredamos el nombre, edad, saldo y número de cuenta de la clase padre (Cuenta)
  credito = t_credito;
  limCredito = t_credito;
}

void CuentaCredito::mostrarCuenta(){ // Se muestra diferente que la clase CuentaAhorro
  cout << "--------------------------------------" << endl;
  cout << "\nTipo de cuenta: " << tipo << endl;
  cout << "Cliente: " << cliente.getNombre() << endl;
  cout << "Saldo: " << saldo << endl;
  cout << "Código de cliente: " << noCuenta << endl;
  cout << "Límite de crédito: " << limCredito << endl;
  cout << "Crédito diponible: " << credito << endl;
  cout << "--------------------------------------" << endl;
}

/*
Con esta función se modifica el saldo del usuario
*/
void CuentaCredito::retirar(float cantidad){
  saldo = saldo - cantidad;
  cout << "Saldo actual: " << saldo << endl;
}

/*
Esta función le permite al usuario usar su tarjeta 
No modifica su saldo
Si no hay crédito suficiente se imprime un mensaje
Imprime el crédito restante en la cuenta
*/
void CuentaCredito::usarTarjeta(float cantidad){
  if ((credito - cantidad) >= 0){
    credito = credito - cantidad;
  }
  else{
    cout << "No hay crédito suficiente " << endl;
  }
  cout << "Credito restante: " << credito << endl;
}

/*
Esta función permite que el usuario pueda pagar su tarjeta de crédito con el saldo que tiene.
Se modifica el saldo del usuario
Imprime el saldo actual
*/
void CuentaCredito::pagarTarjeta(){
  float monto = limCredito - credito;
  credito = limCredito;
  saldo = saldo - monto;
  cout << "Saldo actual: " << saldo << endl;
}

/*
Métodos de acceso
*/
void CuentaCredito::setCredito(float t_credito){
  credito = t_credito;
}

float CuentaCredito::getCredito(){
  return credito;
}

void CuentaCredito::setLimCredito(float t_limCredito){
  limCredito = t_limCredito;
}

float CuentaCredito::getLimCredito(){
  return limCredito;
}

#endif