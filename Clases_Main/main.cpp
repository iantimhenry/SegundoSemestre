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
  int tipo = 0;
  int opciona = 0;
  int opcionb = 0;
  int noCuenta = 0;
  BaseDeDatos bd;

  //Menú
  while (true){
    cout << "¡Bienvenido!" << endl;
    cout << "\n¿Es usted ciente (1) o ejecutivo (2)?" << endl;
    cout << "Ingrese el número de la opción que desea: "; cin >> tipo;
    if (tipo == 1){ //Cliente
      
      cout << "\nIngrese su numero de cuenta"; cin >> noCuenta;
      cout << "¿Qué desea hacer a continuación?" << endl;
      cout << "1) Retirar" << endl;
      cout << "2) Depositar" << endl;
      cout << "3) Salir" << endl;
      cout << "Ingrese el número de la opción que desea: "; cin >> opciona;
      if (opciona == 1){ //Retirar
        int cantidadr = 0;
        cout << "Ingrese la cantidad que desea retirar: "; cin >> cantidadr;
        
        Cuenta*c = bd.seleccionarCuenta(noCuenta);
        c->retirar(cantidadr);
      }
      else if (opciona == 2){ //Depositar
        int cantidadd = 0;
        cout << "Ingrese la cantidad que desea depositar: "; cin >> cantidadd;

        Cuenta*ca = bd.seleccionarCuenta(noCuenta);
        ca->depositar(cantidadd);
      }
      else if (opciona == 3){ //Salir
        
      }
      else{
        cout << "Opción inválida, intente de nuevo" << endl;
      }
      
    }
    else if (tipo == 2){ //Ejecutivo
      cout << "\n¿Qué desea hacer a continuación?" << endl;
      cout << "1) Agregar una nueva cuenta" << endl;
      cout << "2) Eliminar una cuenta existente" << endl;
      cout << "3) Ver cuentas existentes" << endl;
      cout << "4) Salir" << endl;
      cout << "Ingrese el número de la opción que desea: "; cin >> opcionb;
      if (opcionb == 1){ //Agregar cuenta
        int cuenta = 0;
        
        cout << "¿Que tipo de cuenta es?" << endl;
        cout << "1) Cuenta de Ahorros" << endl;
        cout << "2) Cuenta de Crédito" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingrese el número de la opción que desea: "; cin >> cuenta;
        if (cuenta == 1){ //Agregar cuenta de ahorros
          string nombre = "";
          float saldo = 0;
          int noCuenta = 0;
          float interes = 0;
          float saldoMinimo = 0;

          cout << "Ingrese el nombre del cliente: "; cin >> nombre;
          cout << "Ingrese el saldo actual del cliente: "; cin >> saldo;
          cout << "Ingrese el numero de cuenta: "; cin >> noCuenta;
          cout << "Ingrese la tasa de interés anual del cliente en decimales: "; cin >> interes;
          cout << "Ingrese el saldo mínimo del cliente: "; cin >> saldoMinimo;

          bd.agregaAhorro(nombre, saldo, noCuenta, interes, saldoMinimo);

        }
        else if (cuenta == 2){ //Agregar cuenta de crédito
          string _nombre = "";
          float _saldo = 0;
          int _noCuenta = 0;
          float credito= 0;

          cout << "Ingrese el nombre del cliente: "; cin >> _nombre;
          cout << "Ingrese el saldo actual del cliente: "; cin >> _saldo;
          cout << "Ingrese el numero de cuenta: "; cin >> _noCuenta;
          cout << "Ingrese el límite de crédito del cliente: "; cin >> credito;

          bd.agregaCredito(_nombre, _saldo, _noCuenta, credito);
        }
        else if (cuenta == 3){ //Salir

        }
      }
      else if (opcionb == 2){ //Eliminar cuenta
        int cuenta = 0;
        cout << "Ingrese el número de la cuenta que sedea eliminar: ";cin >> cuenta;

        //bd.eliminaCuenta(cuenta);

      }
      else if (opcionb == 3){ //Ver cuentas
        bd.mostrarLista();
      }
      else if (opcionb == 4){ //Salir
      
      }
      else{
       cout << "Opción inválida, intente de nuevo" << endl;
      }
    }
    else{
      cout << "Opción inválida, intente de nuevo " << endl;
    }
  }

  return 0;
}
