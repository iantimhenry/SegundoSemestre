/*
Proyecto Segundo Semestre
Ian Timothy Henry Suárez
A01701578
*/

#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"
#include "CuentaAhorro.h"
#include "CuentaCredito.h"

class BaseDeDatos{ // Creamos la clase Base de Datos 
  
  private: //Atributos
    int tempC;
    Cuenta *cuentas[100];
  
  public: //Métodos
    BaseDeDatos(); // Constructor default
    
    void agregaAhorro(string, string, float, int, float, float);
    void agregaCredito(string, string, float, int, float);
    void mostrarLista();
    Cuenta* seleccionarCuenta(int);
    void eliminaCuenta(int);
};

BaseDeDatos::BaseDeDatos(){
  tempC = 0;
}

/*
Con esta función se crea un objeto de la clase CuentaAhorro con 'new' y se agrega a la lista
*/
void BaseDeDatos::agregaAhorro(string tipo, string nombre, float saldo, int noCuenta, float interes, float saldoMinimo){ 
  cuentas[tempC] = new CuentaAhorro(tipo, nombre, saldo, noCuenta, interes, saldoMinimo);
  tempC++;

}

/*
Con esta función se crea un objeto de la clase CuentaCredito con 'new' y se agrega a la lista
*/
void BaseDeDatos::agregaCredito(string tipo, string nombre, float saldo, int noCuenta, float credito){
  cuentas[tempC] = new CuentaCredito(tipo, nombre, saldo, noCuenta, credito);
  tempC++;
}

/*
Se muestra la lista
Se imprimen los datos de cáda objeto
Se usa polimorfismo para poder imprimir los objetos tanto de la clase CuentaAhorro,
como de la clase CuentaCredito
*/
void BaseDeDatos::mostrarLista(){
  for (int i=0; i<tempC; i++){
    cuentas[i]->mostrarCuenta();
  }
}

/*
Esta función sirve para poder seleccionar un objeto en particular con base en un índice (código de cliente, en el proyecto se llama 'noCuenta')
Esta función la usamos en el main para que el usuario seleccione su cuenta con su código de Cliente
De esta forma puede usar las funciones de la clase en su cuenta particular
*/
Cuenta* BaseDeDatos::seleccionarCuenta(int t_noCuenta){
  for (int i=0; i<tempC; i++){
    Cuenta *actual = cuentas[i];
    if (actual->getNoCuenta() == t_noCuenta){
      return actual;
    }
  }
  return 0;
}

/*
Esta función sirve para eliminar los valores de los objetos que ya no se desean usar
*/
void BaseDeDatos::eliminaCuenta(int cuenta){
  for(int i=0; i<tempC; i++){
    Cuenta *act = cuentas[i];
    if (act->getNoCuenta() == cuenta){
      string clase = act->getTipo();
      if (clase == "Ahorro"){
        act->setTipo("");
        act->setCliente("");
        act->setSaldo(0.0);
        act->setNoCuenta(0);
        dynamic_cast<CuentaAhorro*>(act)->setInteres(0.0);
        dynamic_cast<CuentaAhorro*>(act)->setSaldoMinimo(0.0);
      }
      else if (clase == "Credito"){
        act->setTipo("");
        act->setCliente("");
        act->setSaldo(0.0);
        act->setNoCuenta(0);
        dynamic_cast<CuentaCredito*>(act)->setLimCredito(0.0);
        dynamic_cast<CuentaCredito*>(act)->setCredito(0.0);
        
      }
    }
  }
}

#endif