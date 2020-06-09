/*
Proyecto Segundo Semestre
Ian Timothy Henry Suárez
A01701578
*/

#ifndef CUENTA_H_
#define CUENTA_H_

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"

class Cuenta{ // Declaramos la clase abstracta
  
  protected: // Atributos
    string tipo;
    Cliente cliente; // Composición 
    float saldo;
    int noCuenta; //Actúa como código de cliente
  
  public: //Métodos 
    Cuenta(); // Constructor default
    Cuenta(string, string, float, int); // Constructor con sobrecarga
    virtual void mostrarCuenta() = 0; // Método vitrtual, para polimorfismo 
    virtual void retirar(float) = 0; // Método vitrtual, para polimorfismo 
    void depositar(float);
    /*
    Métodos de acceso
    */
    void setCliente(string);
    string getCliente();
    void setSaldo(float);
    float getSaldo();
    void setNoCuenta(int);
    int getNoCuenta();
    void setTipo(string);
    string getTipo();
};

Cuenta::Cuenta(){
}

Cuenta::Cuenta(string t_tipo, string t_nombre, float t_saldo, int t_noCuenta) : cliente(t_nombre){ // El nombre pertenece al objeto cliente de clase Cliente
  tipo = t_tipo;
  saldo = t_saldo;
  noCuenta = t_noCuenta;
}

/*
Función que usarán todas las clases hijas
*/
void Cuenta::depositar(float cantidad){
  saldo = saldo + cantidad;
  cout << "Saldo actual: " << saldo << endl;
}

/*
Métodos de acceso
*/
void Cuenta::setCliente(string t_nom){
  cliente.setNombre(t_nom);
}

string Cuenta::getCliente(){
  string nom = cliente.getNombre();
  return nom;
}

void Cuenta::setSaldo(float t_saldo){
  saldo = t_saldo;
}
    
float Cuenta::getSaldo(){
  return saldo;
}

void Cuenta::setNoCuenta(int t_noCuenta){
  noCuenta = t_noCuenta;
}

int Cuenta::getNoCuenta(){
  return noCuenta;
}

void Cuenta::setTipo(string t_tipo){
  tipo = t_tipo;
}

string Cuenta::getTipo(){
  return tipo;
}

#endif