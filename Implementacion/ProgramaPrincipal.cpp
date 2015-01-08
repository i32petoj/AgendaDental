#include "Agenda.h"
#include "Cliente.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

int opcion=1;
Agenda aux("Agenda.txt");
string apellido;
string respuesta;
string copia;
list<Cliente> Buscados;

cout << "Bienvenido a la agenda dental" << endl;

aux.ficheroALista();

while(opcion != 0){

    cout << "Elija una de las siguientes opciones: " << endl;

    cout << "*****************************************" << endl;
    cout << "|\tSalir :                           0\t|" << endl;
    cout << "|\tImprimir clientes por pantalla:   1\t|" << endl;
    cout << "|\tBuscar un cliente:                2\t|" << endl;
    cout << "|\tAñadir un cliente:                3\t|" << endl;
    cout << "|\tModificar un cliente:             4\t|" << endl;
    cout << "|\tBorrar un cliente:                5\t|" << endl;
    cout << "|\tMostrar los clientes favoritos    6\t|" << endl;
    cout << "|\tMostrar los clientes mas buscados 7\t|" << endl;
    cout << "|\tCrear copia de seguridad          8\t|" << endl;
    cout << "|\tRestaurar copia de seguridad      9\t|" << endl;
    cout << "****************************************" << endl << endl;


    cout << "Opción -> ";
    cin >> opcion;
    cout << endl;

    switch(opcion){

      case 0: aux.listaAFichero();
              cout << "Gracias por su visita" << endl;
              break;


      case 1: 

                aux.imprimirLista(aux.getArrayClientes());

              //else{
                //cout << "Fallo al cargar fichero, reiniciando... 99%%" << endl;
              //}

              break;

      case 2: getchar();
              Buscados.clear();
              cout << "Introduzca el apellido del cliente que desea buscar" << endl;
              getline(cin,apellido);
              Buscados = aux.buscarCliente(apellido);
              if(!Buscados.empty()){
                aux.imprimirLista(Buscados);
              }else{
                cout << "No hay apellidos coincidentes" << endl;
              }
              break;

      case 3:	getchar();
            if(aux.insertarCliente()){
      				cout<<"Se ha introducido el cliente con exito"<<endl;
      			}else{
      				cout<<"Ya existen clientes"<<endl;
      			}
              break;

      case 4: getchar();
              cout << "Introduzca el apellido del cliente que desea modificar" << endl;
              getline(cin,apellido);
              if(aux.modificarCliente(apellido)){
                cout << "Cliente modificado" << endl;
              }else{
                cout << "El cliente solicitado no se encuentra en la agenda" << endl;
                do{
                cout << "¿Desea añadir el cliente a la agenda?S/N" << endl;
                cin >> respuesta;
                if(respuesta=="S"){
                  aux.insertarCliente();
                }
              }while(respuesta!="S" || respuesta!="N");
              }
              break;

      case 5: getchar();
              cout << "Introduzca el apellido del cliente que desea borrar" << endl;
              getline(cin,apellido);
              if(aux.borrarCliente(apellido)){
                cout << "Cliente borrado" << endl;
              }else{
                cout << "El cliente no se encuentra en la agenda o ya ha sido borrado" << endl;
              }
              break;

      case 6: aux.imprimirLista(aux.muestraFavoritos());
              break;

      case 7: aux.imprimirLista(aux.mostrarClientesMasBuscados());
              break;

      case 8: getchar();
              cout << "Introduzca el nombre que desea darle a la copia" << endl;
              getline(cin,copia);
              if(aux.hacerCopiaSeguridad(copia)){
                cout << "Copia realizada" << endl;
              }else{
                cout << "No se encuentra el fichero de la agenda" << endl;
              }
              break;

      case 9: getchar();
              cout << "Introduzca el nombre de la copia que desea restaurar" << endl;
              getline(cin,copia);
              if(aux.restaurarCopiaSeguridad(copia)){
                aux.ficheroALista();
                cout << "Agenda restaurada" << endl;
              }else{
                cout << "No se encuentra el fichero de la copia" << endl;
              }
              break;

      default:  cout << "Opción no valida" << endl;



    }




}





  return 0;
}
