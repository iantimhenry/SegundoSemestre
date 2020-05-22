#ifndef CUENTA_H_
#define CUENTA_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"

class Cuenta{
  protected:
    Cliente cliente;
    float saldo;
    int noCuenta;
  public:
    Cuenta();
    Cuenta(string, int, float, int);
    void retirar(float);
    void depositar(float);
    void setNoCuenta(int);
    int getNoCuenta();
};

Cuenta::Cuenta(){
}

Cuenta::Cuenta(string _nombre, int _edad, float _saldo, int _noCuenta){
  saldo = _saldo;
  noCuenta = _noCuenta;
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

class CuentaAhorro : public Cuenta{
  private:
    float interes;
    float saldoMinimo
  public:
    CuentaAhorro();
    CuentaAhorro(string, int, float, int, float, float);
    void retirar(float); // Sobreescritura
    void setInteres(float);
    void setSaldoMinimo(float);
    float getInteres();
    float getSaldoMinimo();
};

CuentaAhorro::CuentaAhorro(){
}

CuentaAhorro::CuentaAhorro(string _nombre, int _edad, float _saldo, int _noCuenta, float _interes, float _saldoMinimo) : Cuenta(_nombre, _edad, _saldo, _noCuenta){
  interes = _interes;
  saldoMinimo = _saldoMinimo;
}

void CuentaAhorro::retirar(float cantidad){
  if ((saldo - cantidad) >= saldoMinimo){
    saldo = saldo - cantidad
  }
  else {
    cout << "No es posible retirar esa cantidad, intente con una cantidad menor, que no lleve el saldo a ser menor que el saldo mínimo"
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


class CuentaCredito : public Cuenta{
  private:
    float credito;
    float limCredito;
  public:
    CuentaCredito();
    CuentaCredito(string, int, float, int, float);
    setLimCredito(float);
    getLimCredito();
    void usarTarjeta(float);
    void pagarTarjeta();
};

CuentaCredito(){
}

CuentaCredito(string _nombre, int _edad, float _saldo, int _noCuenta, float _credito) : Cuenta(_nombre, _edad, _saldo, _noCuenta){
  credito = _credito;
  limCredito = _credito;
}

void CuentaCredito::setLimCredito(float _limcredito){
  limCredito = _limcredito;
}

float CuentaCredito::getLimCredito(){
  return limCredito;
}

void CuentaCredito::usarTarjeta(float cantidad){
  if (credito-cantidad) > 0{
    credito = credito - cantidad;
  }
  else{
    cout << "No hay crédito suficiente"
  }
}

void CuentaCredito::pagarTarjeta(){
  monto = limCredito - credito;
  credito = limCredito;
  saldo = saldo - monto;
}

#endif