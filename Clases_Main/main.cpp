/*
Proyecto Segundo Semestre
Ian Timothy Henry Suárez
A01701578
*/

#include <iostream>
#include <string>
using namespace std;

#include "Cliente.h"
#include "Cuenta.h"
#include "CuentaAhorro.h"
#include "CuentaCredito.h"
#include "BaseDeDatos.h"


int main(){

  int tipo = 0; // Variable para separar ejecutivos de clientes
  int opcionA = 0; // Variable para opciones de cliente de ahorro
  int opcionC = 0; // Variable para opciones de cliente de crédito
  int opcionE = 0; // Variable para opciones del ejecutivo
  int noCuenta = 0; // Variable para identificar cuentas
  bool corre = true;

  BaseDeDatos bd;

  //Menú
  while (corre){

    cout << "\n¡Bienvenido!" << endl;
    cout << "\n¿Es usted cliente (1) o ejecutivo (2)?" << endl;
    cout << "\nIngrese el número de la opción que desea: "; cin >> tipo;

    if (tipo == 1){ // Opciones del cliente
      
      cout << "\nIngrese su código de cliente: "; cin >> noCuenta; 

      Cuenta*c = bd.seleccionarCuenta(noCuenta); //Cuenta con la que trabajamos
      
      if (c == 0){
        cout << "El código de cliente es incorrecto o no existe" << endl;
      } 
      else{
        string tipoC = c->getTipo();

        if (tipoC == "Ahorro"){ //Opciones cuenta ahorro

          cout << "\n¿Qué desea hacer a continuación?" << endl;
          cout << "1) Retirar" << endl;
          cout << "2) Depositar" << endl;
          cout << "3) Salir" << endl;
          cout << "\nIngrese el número de la opción que desea: "; cin >> opcionA;

          if (opcionA == 1){ //Retirar
            int cantidadar = 0;

            cout << "\nIngrese la cantidad que desea retirar: "; cin >> cantidadar;
          
            c->retirar(cantidadar);
          }
          else if (opcionA == 2){ //Depositar
            int cantidadad = 0;

            cout << "\nIngrese la cantidad que desea depositar: "; cin >> cantidadad;

            c->depositar(cantidadad);
          }
          else if (opcionA == 3){ //Salir
            corre = false;
          }
          else{
          cout << "Opción inválida, intente de nuevo" << endl;
          }

        }
        else if(tipoC == "Credito"){ //Opciones cuenta crédito 

          cout << "\n¿Qué desea hacer a continuación?" << endl;
          cout << "1) Retirar" << endl;
          cout << "2) Depositar" << endl;
          cout << "3) Usar tarjeta" << endl;
          cout << "4) Pagar tarjeta" << endl;
          cout << "5) Salir" << endl;
          cout << "\nIngrese el número de la opción que desea: "; cin >> opcionC;

          if (opcionC == 1){ //Retirar
            int cantidadcr = 0;

            cout << "\nIngrese la cantidad que desea retirar: "; cin >> cantidadcr;
          
            c->retirar(cantidadcr);
          }
          else if (opcionC == 2){ //Depositar
            int cantidadcd = 0;

            cout << "\nIngrese la cantidad que desea depositar: "; cin >> cantidadcd;

            c->depositar(cantidadcd);
          }
          else if (opcionC == 3){ //Usar tarjeta 
            int cantidadct = 0;

            cout << "\nIngrese la cantidad que desea usar de su tarjeta de crédito: "; cin >> cantidadct;

            dynamic_cast<CuentaCredito*>(c)->usarTarjeta(cantidadct);      
          }
          else if (opcionC == 4){ //Pagar tarjeta 
            dynamic_cast<CuentaCredito*>(c)->pagarTarjeta();
          }
          else if (opcionC == 5){ //Salir
            corre = false;
          }
          else{
            cout << "Opción inválida, intente de nuevo" << endl;
          }
        }
      } // Else
    }

    else if (tipo == 2){ // Opciones del ejecutivo

      cout << "\n¿Qué desea hacer a continuación?" << endl;
      cout << "1) Agregar una nueva cuenta" << endl;
      cout << "2) Eliminar una cuenta existente" << endl;
      cout << "3) Ver cuentas existentes" << endl;
      cout << "4) Salir" << endl;
      cout << "\nIngrese el número de la opción que desea: "; cin >> opcionE;

      if (opcionE == 1){ //Agregar cuenta

        int cuenta = 0; //Variable para opcion de tipo de cuenta
        
        cout << "\n¿Que tipo de cuenta es?" << endl;
        cout << "1) Cuenta de Ahorros" << endl;
        cout << "2) Cuenta de Crédito" << endl;
        cout << "3) Salir" << endl;
        cout << "\nIngrese el número de la opción que desea: "; cin >> cuenta;

        if (cuenta == 1){ //Agregar cuenta de ahorros

          string nombre = "";
          float saldo = 0;
          int noCuenta = 0;
          float interes = 0;
          float saldoMinimo = 0;
          string tipo = "Ahorro";

          cout << "\nIngrese el nombre del cliente: "; cin >> nombre;
          cout << "Ingrese el saldo actual del cliente: "; cin >> saldo;
          cout << "Ingrese el código del cliente: "; cin >> noCuenta;
          cout << "Ingrese la tasa de interés anual del cliente en decimales: "; cin >> interes;
          cout << "Ingrese el saldo mínimo del cliente: "; cin >> saldoMinimo;

          bd.agregaAhorro(tipo, nombre, saldo, noCuenta, interes, saldoMinimo);

        }
        else if (cuenta == 2){ //Agregar cuenta de crédito

          string t_nombre = "";
          float t_saldo = 0;
          int t_noCuenta = 0;
          float credito= 0;
          string t_tipo = "Credito";

          cout << "\nIngrese el nombre del cliente: "; cin >> t_nombre;
          cout << "Ingrese el saldo actual del cliente: "; cin >> t_saldo;
          cout << "Ingrese el código del cliente: "; cin >> t_noCuenta;
          cout << "Ingrese el límite de crédito del cliente: "; cin >> credito;

          bd.agregaCredito(t_tipo, t_nombre, t_saldo, t_noCuenta, credito);

        }
        else if (cuenta == 3){ //Salir
          corre =  false;
        }
      }
      else if (opcionE == 2){ //Eliminar cuenta 
        int cuentaElim = 0;

        cout << "\nIngrese el código de cliente de la cuenta que desea eliminar: ";cin >> cuentaElim;

        bd.eliminaCuenta(cuentaElim);

      }
      else if (opcionE == 3){ //Ver cuentas
        bd.mostrarLista();
      }
      else if (opcionE == 4){ //Salir
        corre = false;
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
