#ifndef CUENTA_H_
#define CUENTA_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"

class Cuenta{ // Creamos la clase padre (Cuenta) 
  protected:
    Cliente cliente; // Composición 
    float saldo;
    int noCuenta;
  public:
    Cuenta(); // Constructor default
    Cuenta(string, float, int); // Constructor con sobre carga
    virtual void mostrarCuenta(); // Método vitrtual, para polimorfismo
    virtual void retirar(float); // Método vitrtual, para polimorfismo
    void depositar(float);
    void setNoCuenta(int);
    int getNoCuenta();
    
};

Cuenta::Cuenta(){
}

Cuenta::Cuenta(string _nombre, float _saldo, int _noCuenta) : cliente(_nombre){ // El nombre pertenece al objeto cliente de clase Cliente
  saldo = _saldo;
  noCuenta = _noCuenta;
}

void Cuenta::mostrarCuenta(){
  cout << "Cliente: " << cliente.getNombre() << endl;
  cout << "Saldo: " << saldo << endl;
  cout << "Número de cuenta: " << noCuenta << endl;
}

void Cuenta::retirar(float cantidad){
  saldo = saldo - cantidad;
}

void Cuenta::depositar(float cantidad){
  saldo = saldo + cantidad;
}

void Cuenta::setNoCuenta(int _noCuenta){
  noCuenta = _noCuenta;
}

int Cuenta::getNoCuenta(){
  return noCuenta;
}

class CuentaAhorro : public Cuenta{ // Creamos una clase hija (CuentaAhorro)
  private:
    float interes;
    float saldoMinimo;
  public:
    CuentaAhorro(); // Constructor default
    CuentaAhorro(string, float, int, float, float); // Constructor con sobre carga
    void mostrarCuenta(); // Sobreescritura
    void retirar(float); // Sobreescritura
    void setInteres(float);
    void setSaldoMinimo(float);
    float getInteres();
    float getSaldoMinimo();
};

CuentaAhorro::CuentaAhorro(){
}

CuentaAhorro::CuentaAhorro(string _nombre, float _saldo, int _noCuenta, float _interes, float _saldoMinimo) : Cuenta(_nombre, _saldo, _noCuenta){ // Heredamos el nombre, edad, saldo y número de cuenta de la clase padre (Cuenta)
  interes = _interes;
  saldoMinimo = _saldoMinimo;
}

void CuentaAhorro::mostrarCuenta(){ // Se muestra diferente que la clase padre
  cout << "Cliente: " << cliente.getNombre() << endl;
  cout << "Saldo: " << saldo << endl;
  cout << "Número de cuenta: " << noCuenta << endl;
  cout << "Tasa de interés anual: " << (interes*100) << endl;
  cout << "Saldo mínimo: " << saldoMinimo << endl;
}

void CuentaAhorro::retirar(float cantidad){ // Declaramos la función retirar para la clase CuentaAhorro
  if ((saldo - cantidad) >= saldoMinimo){
    saldo = saldo - cantidad;
  }
  else {
    cout << "No es posible retirar esa cantidad, no hay saldo suficiente"<<endl;
  }
}

void CuentaAhorro::setInteres(float _interes){
  interes = _interes;
}

void CuentaAhorro::setSaldoMinimo(float _saldoMinimo){
  saldoMinimo = _saldoMinimo;
}

float CuentaAhorro::getInteres(){
  return interes;
}

float CuentaAhorro::getSaldoMinimo(){
  return saldoMinimo;
}

class CuentaCredito : public Cuenta{ // Creamos una clase hija (CuentaCredito)
  private:
    float credito;
    float limCredito;
  public:
    CuentaCredito(); // Constructor default
    CuentaCredito(string, float, int, float); // Constructor con sobre carga
    void mostrarCuenta();
    void setLimCredito(float);
    float getLimCredito();
    void usarTarjeta(float);
    void pagarTarjeta();
};

CuentaCredito::CuentaCredito(){
}

CuentaCredito::CuentaCredito(string _nombre, float _saldo, int _noCuenta, float _credito) : Cuenta(_nombre, _saldo, _noCuenta){
  credito = _credito;
  limCredito = _credito;
}

void CuentaCredito::mostrarCuenta(){ // Se muestra diferente que la clase padre
  cout << "Cliente: " << cliente.getNombre() << endl;
  cout << "Saldo: " << saldo << endl;
  cout << "Número de cuenta: " << noCuenta << endl;
  cout << "Límite de crédito: " << limCredito << endl;
  cout << "Crédito diponible: " << credito << endl;
}

void CuentaCredito::setLimCredito(float _limCredito){
  limCredito = _limCredito;
}

float CuentaCredito::getLimCredito(){
  return limCredito;
}

void CuentaCredito::usarTarjeta(float cantidad){
  if ((credito - cantidad) >= 0){
    credito = credito - cantidad;
  }
  else{
    cout << "No hay crédito suficiente"
  }
}

void CuentaCredito::pagarTarjeta(){
  float monto = limCredito - credito;
  credito = limCredito;
  saldo = saldo - monto;
}

#endif