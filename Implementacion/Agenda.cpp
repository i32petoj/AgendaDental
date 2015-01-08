/*
 * Agenda.cpp
 *
 *  Created on: 04/12/2014
 *      Author: i32mezar
 */

#include "Agenda.h"
#include "Cliente.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cctype>

 using namespace std;

	/*-----------------------------------------------------------------------------------------

										CONSTRUCTOR

	-----------------------------------------------------------------------------------------*/


	Agenda::Agenda(string ficheroAgenda) {

		setNombreFichero(ficheroAgenda);
		arrayClientes_.clear();
	}


	/*-----------------------------------------------------------------------------------------

									FUNCION PEDIR DATOS CLIENTE

	-----------------------------------------------------------------------------------------*/

	Cliente pedirDatos(){

		//Creamos un cliente auxiliar para devolverlo

		Cliente aux;

		//DECLARACION DE VARIABLES

		string nombre="", apellidos="", DNI="", anotaciones="";
		char opcion;
		bool favorito;
		int opcionMenu;

		string calle="", puerta="";
		string portal="";
		Direcciones direccion;

		string facebook="";
		string twitter="";
		string tuenti="";
		string linkedin="";
		Redes redes;
		int opcionRedes;


		string hotmail="";
		string gmail="";
		string yahoo="";
		Correos correos;


		string numeroFijo="";
		string numeroMovil1="";
		string numeroMovil2="";
		Telefonos telefonos;


		//Vamos asignando valores por teclado a las variables

		cout<<"Introduce el nombre: ";
		getline(cin, nombre);
		cout<<"Introduce los apellidos: ";
		getline(cin, apellidos);
		cout<<"Introduce DNI: ";
		getline(cin, DNI);

		cout<<"Introduce calle: ";
		getline(cin, calle);
		cout<<"Introduce numero: ";
		getline(cin,portal);
		cout<<"Introduce puerta: ";
		getline(cin, puerta);
		direccion.calle=calle;
		direccion.puerta=puerta;
		direccion.portal=portal;

		cout<<"Introduce anotacion: ";
		getline(cin, anotaciones);

				cout<<"¿Es favorito? (s/n): ";
				cin>>opcion;

				if(opcion=='s'){
					favorito=1;
				}else{
					favorito=0;
				}

		do{
			cout<<"¿Que redes tiene?"<<endl;
			cout<<"\t1.Twitter"<<endl;
			cout<<"\t2.Facebook"<<endl;
			cout<<"\t3.Tuenti"<<endl;
			cout<<"\t4.Linkedin"<<endl;
			cout<<"\t0.Salir"<<endl;
			cout<<"Opcion: ";
			cin>>opcionMenu;

					getchar();

					switch(opcionMenu){

						case 0: break;

						case 1: cout<<"Introduce usuario twitter: ";
								getline(cin, twitter);
								redes.twitter = twitter;
								break;

						case 2: cout<<"Introduce usuario facebook: ";
								getline(cin, facebook);
								redes.facebook = facebook;
								break;

						case 3: cout<<"Introduce usuario tuenti: ";
								getline(cin, tuenti);
								redes.tuenti = tuenti;
								break;

						case 4: cout<<"Introduce usuario linkedin: ";
								getline(cin, linkedin);
								redes.linkedin = linkedin;
								break;

						default: cout<<"OPCION NO VALIDA";
								break;


					}

		}while(opcionMenu!=0);

			do{
						cout<<"¿Cual es el correo?"<<endl;
						cout<<"\t1.Gmail\n"<<endl;
						cout<<"\t2.Hotmail"<<endl;
						cout<<"\t3.Yahoo"<<endl;
						cout<<"\t0.Salir"<<endl;
						cout<<"Opcion: ";
						cin>>opcionMenu;
						getchar();

						switch(opcionMenu){

							case 0: break;

							case 1: cout<<"Introduce tu direccion: ";
									getline(cin, gmail);
									correos.gmail=gmail;
									break;

							case 2: cout<<"Introduce tu direccion: ";
									getline(cin, hotmail);
									correos.hotmail=hotmail;
									break;

							case 3: cout<<"Introduce tu direccion: ";
									getline(cin, yahoo);
									correos.yahoo=yahoo;
									break;

							default: cout<<"OPCION NO VALIDA";
									break;
						}

			}while(opcionMenu!=0);



			do{
						cout<<"¿Numero de telefono??"<<endl;
						cout<<"\t1.Fijo"<<endl;
						cout<<"\t2.Movil1"<<endl;
						cout<<"\t3.Movil2"<<endl;
						cout<<"\t0.Salir"<<endl;
						cout<<"Opcion: ";
						cin>>opcionMenu;
						getchar();
						switch(opcionMenu){

							case 0: break;

							case 1: cout<<"Introduce tu numero fijo: ";
									cin>>numeroFijo;
									telefonos.numeroFijo=numeroFijo;
									break;

							case 2: cout<<"Introduce tu movil: ";
									cin>>numeroMovil1;
									telefonos.numeroMovil1=numeroMovil1;
									break;

							case 3: cout<<"Introduce tu movil2: ";
									cin>>numeroMovil2;
									telefonos.numeroMovil2=numeroMovil2;
									break;

							default: cout<<"OPCION NO VALIDA";
									break;
						}

			}while(opcionMenu!=0);

		//SE MODIFICAN LAS VARIABLES DEL CLIENTE AUX CON LOS VALORES ASIGNADOS


		aux.setNombre(nombre);
		aux.setApellidos(apellidos);
		aux.setDni(DNI);
		aux.setAnotaciones(anotaciones);
		aux.setFavorito(favorito);
		aux.setMasUsados(0);
		aux.setRedes(redes);
		aux.setDirecciones(direccion);
		aux.setCorreos(correos);
		aux.setTelefonos(telefonos);

		return (aux);
	}

	/*-----------------------------------------------------------------------------------------

									FUNCION INSERTAR CLIENTE

	-----------------------------------------------------------------------------------------*/

	bool Agenda::insertarCliente(){

		string apellido;
		list<Cliente> aux;
		Cliente c;
    int elementos;

		cout<<"Introduce el apellido del cliente: ";
		getline(cin, apellido);

		aux = buscarCliente(apellido);//Se buscan los clientes que tengan ese apellido, y se devuelve la lista de clientes.
    elementos = aux.size();
    if(elementos==0){
		imprimirLista(aux);//Imprime la lista de clientes con ese apellido
		c = pedirDatos();//Pide los datos por pantalla y devuelve el cliente con esos datos
		introducirEnLista(c);//Introduce al cliente en la lista
		ordenarClientes();//Ordena la lista por apellido con el nuevo cliente
			return (true);
		}else{
			return (false);//Si ya existe un cliente con ese apellido, devuelve false
		}
	}

	/*-----------------------------------------------------------------------------------------

								FUNCIONES AUXILIARES PARA INSERTAR CLIENTE
									- INTRODUCIR EN LA LISTA
												Y
									- IMPRIMIR LISTA COMPROBANDO

	-----------------------------------------------------------------------------------------*/

				void Agenda::introducirEnLista(const Cliente &c){
						arrayClientes_.push_back(c);
					}

					void Agenda::imprimirListaComprobando( list <Cliente> aux, const string &apellido){

						list<Cliente>::iterator i;
						int j=1;

						cout<<"CLIENTES CON APELLIDO < "<<apellido<<" >\n";
						cout<<"-----------------------------------------\n\n";

						for(i=aux.begin(); i!=aux.end(); ++i){
							if((i->getApellidos())==apellido){
								cout<<j<<" ) Cliente con nombre < "<<i->getApellidos()<<", "<<i->getNombre()<<" > y DNI < "<<i->getDni()<<" >\n";
								j++;
							}
						}
					}


	/*-----------------------------------------------------------------------------------------

									FUNCION ORDENAR CLIENTES

	-----------------------------------------------------------------------------------------*/

//Funcion que ordenará la lista de la agenda en función del apellido
//Orden ascendente
bool Agenda::ordenarClientes(){

  //Para ello hacemos uso de la función sort() de la clase list
	arrayClientes_.sort(funcionOrdenacion);

	return(true);

}
      /*---------------------------------------------------------

            FUNCION AUXILIAR PARA ORDENAR LA LISTA
      ----------------------------------------------------------*/

      //Esta función será la que pasaremos a sort() en la funcion ordenarClientes
      //Comparará los apellidos de dos clientes y devolverá verdadero si el primero es menor que el segundo
      //Para que se queden ordenador ascendentemente
    	bool Agenda::funcionOrdenacion(Cliente first, Cliente second){

    	string aux1,aux2;

    	aux1=first.getApellidos();
    	aux2=second.getApellidos();

    	return(aux1<aux2);

    }


	/*-----------------------------------------------------------------------------------------

									FUNCION BUSCAR CLIENTE

	-----------------------------------------------------------------------------------------*/

//Funcion buscarCliente, la cual recibe el apellido por parametro
//Recorrerá toda la lista y nos devolverá una lista con los clientes de apellido coincidente
list <Cliente> Agenda::buscarCliente(string apellido){

	list <Cliente> aux;

	list <Cliente>::iterator it;

  //Recorremos toda la lista con un iterator
	for(it=arrayClientes_.begin();it!=arrayClientes_.end();++it){

		if(it->getApellidos()==apellido){
			it->setMasUsados(it->getMasUsados() + 1);
			aux.push_back(*it);
		}

	}
  //Devolvemos los clientes con apellido coincidente
	return(aux);


}



	/****************************************************************************************

									FUNCION BORRAR CLIENTE

	*******************************************************************************************/



	bool Agenda::borrarCliente(string apellido){

		list<Cliente> aux;
		int elementos;
		Cliente c;
		int posicion;

		aux = buscarCliente(apellido);

    elementos = aux.size();
		if(elementos!=0){
      imprimirListaComprobando(aux, apellido);
			cout<<"Introduce el numero del cliente para eliminar: ";
			cin>>posicion;
			c = sacarClienteListaComprobando(aux, posicion);
      eliminarClienteListaComprobando(arrayClientes_, c);

		/*SEGUN LA POSICION, COGER EL CLIENTE DE AUX
		Y CON EL DNI BORRARLO EN LA LISTA GENERAL
		DESPUES PASARLO A FICHERO
		*/

		}else{

			return (false); /*NO SE ENCUENTRA EL CLIENTE O YA ESTA BORRADO*/

		}

	}

	/*-----------------------------------------------------------------------------------------

									FUNCIONES AUXILIARES PARA BORRAR
									- SACAR CLIENTE DE LA LISTA
													Y
									- ELIMINAR CLIENTE DE LA LISTA

	-----------------------------------------------------------------------------------------*/


						Cliente Agenda::sacarClienteListaComprobando(list <Cliente> &aux, int posicion){

							list<Cliente>::iterator i;
							int j=1;
              int elementos = aux.size();
							Cliente caux;
              if(elementos==1){
                i=aux.begin();
                caux = *i;
              }else{
							for(i=aux.begin(); i!=aux.end(); ++i){
								if(j==posicion){
									caux = *i;
									aux.erase(i);
								}
								j++;
							 }
              }

							return (caux);
						}

						void Agenda::eliminarClienteListaComprobando(list <Cliente> &laux,  Cliente caux){

							string DNI;
							DNI = caux.getDni();
							list<Cliente>::iterator i;
              int elementos = laux.size();

              if(elementos==1){
                i=laux.begin();
                laux.erase(i);
              }else{
							for(i=laux.begin(); i!=laux.end(); ++i){
								if(DNI==i->getDni()){
									laux.erase(i);
								}
							 }
              }
						}

	/*-----------------------------------------------------------------------------------------

									FUNCION MODIFICAR CLIENTE

	-----------------------------------------------------------------------------------------*/


	bool Agenda::modificarCliente(string apellido){

		list<Cliente> aux;
		int elementos;
		Cliente c;
		int posicion;
    bool resultado=false;

		aux = buscarCliente(apellido);
		elementos = aux.size();

  if(elementos!=0){
      imprimirListaComprobando(aux, apellido);
			cout<<"Introduce el numero del cliente para modificar: ";
			cin>>posicion;
			c = sacarClienteListaComprobando(aux, posicion);
      modificarClienteListaComprobando(arrayClientes_, c);
			return (true);

		/*PEDIR DATOS, MODIFICAR EN LA LISTA AUX Y
		MODIFICAR EN LA LISTA GENERAL CON EL DNI
		BORRANDO EL ANTERIOR Y PONIENDO EL NUEVO*/

		}else{
			return (false); /*NO SE ENCUENTRA EL CLIENTE Y PREGUNTAR EN EL MAIN SI DESEA INTRODUCIRLO*/
		}
	}


	/*-----------------------------------------------------------------------------------------

									FUNCIONES AUXILIARES PARA MODIFICAR
									- MODIFICAR CLIENTE DE LA LISTA

	-----------------------------------------------------------------------------------------*/


	void Agenda::modificarClienteListaComprobando(list <Cliente> &laux, Cliente &caux){

		string DNI="";
		DNI = caux.getDni();
		list<Cliente>::iterator i;
							int opcion;

							string nombre="", apellidos="", anotaciones="";
							char favorito;
							int opcionMenu;

							string calle="", puerta="";
							string portal="";
							Direcciones direccion;

							string facebook="";
							string twitter="";
							string tuenti="";
							string linkedin="";
							Redes redes;
							int opcionRedes;


							string hotmail="";
							string gmail="";
							string yahoo="";
							Correos correos;


							string numeroFijo="";
							string numeroMovil1="";
							string numeroMovil2="";
							Telefonos telefonos;

							for(i=laux.begin(); i!=laux.end(); ++i){
								if(DNI==i->getDni()){ //SI EL DNI DEL CLIENTE DE LA LISTA COINCIDE CON EL PARAMETRO DEL DNI
									do{
										cout<<"¿Que desea modificar?"<<endl;
										cout<<"\t1.Nombre"<<endl;
										cout<<"\t2.Apellidos"<<endl;
										cout<<"\t3.DNI"<<endl;
										cout<<"\t4.Anotaciones"<<endl;
										cout<<"\t5.Favorito"<<endl;
										cout<<"\t6.Redes"<<endl;
										cout<<"\t7.Direcciones"<<endl;
										cout<<"\t8.Correos"<<endl;
										cout<<"\t9.Telefonos"<<endl;
										cout<<"\t0. SALIR"<<endl;
										cout<<"Opcion: ";
										cin>>opcion;
                    getchar();

										switch(opcion){
											case 0: break;

											case 1:	cout<<"Introduce el nuevo nombre: ";
													getline(cin, nombre);
													i->setNombre(nombre);
													break;

											case 2:	cout<<"Introduce los nuevos apellidos: ";
													getline(cin, apellidos);
													i->setApellidos(apellidos);
													break;

											case 3:	cout<<"Introduce el nuevo dni: ";
													getline(cin, DNI);
													i->setDni(DNI);
													break;

											case 4:	cout<<"Introduce anotaciones: ";
													getline(cin,anotaciones);
													i->setAnotaciones(anotaciones);
													break;

											case 5:	do{
														cout<<"Introduce si es favorito (s/n): ";
														cin>>favorito;
														if(favorito=='s'){
															i->setFavorito(true);
														}

														if(favorito=='n'){
															i->setFavorito(false);
														}

													}while((favorito!='s')&&(favorito!='n'));//Mientras la opcion no sea s o n, se vuelve a preguntar
													break;

											case 6:	do{
														cout<<"¿Que redes tiene?"<<endl;
														cout<<"\t1.Twitter"<<endl;
														cout<<"\t2.Facebook"<<endl;
														cout<<"\t3.Tuenti"<<endl;
														cout<<"\t4.Linkedin"<<endl;
														cout<<"\t0.Salir"<<endl;
														cout<<"Opcion: ";
														cin>>opcionMenu;
														getchar();
														switch(opcionMenu){

															case 0: break;

															case 1: cout<<"Introduce usuario twitter: ";
																	cin>>twitter;
																	redes.twitter = twitter;
																	break;

															case 2: cout<<"Introduce usuario facebook: ";
																	cin>>facebook;
																	redes.facebook = facebook;
																	break;

															case 3: cout<<"Introduce usuario tuenti: ";
																	cin>>tuenti;
																	redes.tuenti = tuenti;
																	break;

															case 4: cout<<"Introduce usuario linkedin: ";
																	cin>>linkedin;
																	redes.linkedin = linkedin;
																	break;

															default: cout<<"OPCION NO VALIDA"<<endl;
														}
													}while(opcionMenu!=0);
													i->setRedes(redes);
													break;

											case 7:	cout<<"Introduce calle: ";
													getline(cin, calle);
													cout<<"Introduce numero: ";
													cin>>portal;
													cout<<"Introduce puerta: ";
													cin>>puerta;
													direccion.calle=calle;
													direccion.puerta=puerta;
													direccion.portal=portal;
													i->setDirecciones(direccion);
													break;

											case 8:	do{
														cout<<"¿Cual es el correo?"<<endl;
														cout<<"\t1.Gmail"<<endl;
														cout<<"\t2.Hotmail"<<endl;
														cout<<"\t3.Yahoo"<<endl;
														cout<<"\t0.Salir"<<endl;
														cout<<"Opcion: ";
														cin>>opcionMenu;
														getchar();

														switch(opcionMenu){

															case 0: break;

															case 1: cout<<"Introduce tu direccion: ";
																	cin>>gmail;
																	correos.gmail=gmail;
																	break;

															case 2: cout<<"Introduce tu direccion: ";
																	cin>>hotmail;
																	correos.hotmail=hotmail;
																	break;

															case 3: cout<<"Introduce tu direccion: ";
																	cin>>yahoo;
																	correos.yahoo=yahoo;
																	break;

															default: cout<<"OPCION NO VALIDA";
																	break;
														}

													}while(opcionMenu!=0);
													i->setCorreos(correos);
													break;

											case 9:	do{
														cout<<"¿Numero de telefono?"<<endl;
														cout<<"1.Fijo"<<endl;
														cout<<"2.Movil1"<<endl;
														cout<<"3.Movil2"<<endl;
														cout<<"0.Salir"<<endl;
														cout<<"Opcion: ";
														cin>>opcionMenu;
														getchar();

														switch(opcionMenu){

															case 0: break;

															case 1: cout<<"Introduce tu numero fijo: ";
																	cin>>numeroFijo;
																	telefonos.numeroFijo=numeroFijo;
																	break;

															case 2: cout<<"Introduce tu movil: ";
																	cin>>numeroMovil1;
																	telefonos.numeroMovil1=numeroMovil1;
																	break;

															case 3: cout<<"Introduce tu movil2: ";
																	cin>>numeroMovil2;
																	telefonos.numeroMovil2=numeroMovil2;
																	break;

															default: cout<<"OPCION NO VALIDA";
																	break;
														}



													}while(opcionMenu!=0);
													i->setTelefonos(telefonos);
													break;

												}

									}while(opcion!=0);
								}
							}
				}



	/*-----------------------------------------------------------------------------------------

									FUNCION MOSTRAR CLIENTES MAS BUSCADOS

	-----------------------------------------------------------------------------------------*/

	//Esta función imprimirá los 10 clientes mas buscado por la secretaria
list<Cliente> Agenda::mostrarClientesMasBuscados(){

  list <Cliente> Lista;
  list <Cliente> aux;
  list <Cliente>::iterator first;
  list <Cliente>::iterator last;
  int j = 10;
  //Para coger los mas buscados, podemos ordenar la lista por ese campo
  //Una vez ordenada la lista por ese campo, cogeremos los 10 primeros
  aux = getArrayClientes();

  aux.sort(compare_usados);

  //Una vez ordenada dicha lista pasamos los 10 primeros elementos a otra lista
  //Usaremos la funcion splice
  //void splice (iterator position, list& x, iterator first, iterator last);

    //Esto es por si hay menos de 10 clientes en la lista
    if(aux.size()<10){
      j = aux.size();
    }

  first = aux.begin();
  last = aux.begin();
  //Incrementamos el segundo iterador hasta 10 o hasta el numero de clientes que haya si hay < 10
  for(int i=0; i<j;i++){
    ++last;
  }

    Lista.splice(Lista.begin(), aux, aux.begin(), last);


//Finalmente devolvemos la lista con los clientes mas buscados
return (Lista);
}


    /*-----------------------------------------------------------------------------------------

        FUNCION AUXILIAR QUE NOS AYUDARÁ A ORDERNAR LA LISTA SEGUN EL CAMPO DE MASUSADOS

    -----------------------------------------------------------------------------------------*/
    bool Agenda::compare_usados(Cliente first, Cliente second){
      int primero;
      int segundo;
      primero = first.getMasUsados();
      segundo = second.getMasUsados();
      if(primero > segundo){
        return true;
      }else
        return false;
    }

	/*-----------------------------------------------------------------------------------------

									FUNCION MOSTRAR CLIENTES FAVORITOS

	-----------------------------------------------------------------------------------------*/


//Funcion que muestra por pantalla los clientes favoritos
//Es decir, los clientes que tienen "Si" en el campo favorito
list<Cliente> Agenda::muestraFavoritos(){

  list<Cliente> Lista;
  list<Cliente> aux;
  list<Cliente>::iterator i;

  aux = getArrayClientes();
  //Recorremos la lista con un iterator
  //Vamos almacenando en otra lista auxiliar los clientes favoritos
  for(i = aux.begin(); i != aux.end(); ++i){
    if(i->getFavorito()){
      Lista.push_back(*i);
    }
  }
  if(Lista.empty()){
    cout << "No hay favoritos entre los clientes" << endl;
  }

  //Devolvemos solo la lista con clientes favoritos
  return (Lista);
}



/*--------------------------------------------------------------

        FUNCION PARA IMPRIMIR UNA LISTA

----------------------------------------------------------*/


//Funcion que imprimirá una lista de clientes pasada por parametro.
//Para imprimir dicha lista usará el formato de la función imprimeCliente, que recibe un cliente
	void Agenda::imprimirLista(list<Cliente> Lista){

		  list<Cliente>::iterator i;
      //Recorremos la lista de principio a fin con un iterator
      //Pasandole en cada vuelta un cliente a la funcion imprimeCliente
      if(!Lista.empty()){
		      for(i = Lista.begin(); i != Lista.end(); ++i){
		      imprimeCliente(*i);
		    }
      }else{
        cout << "No hay clientes en la lista para imprimir" << endl << endl;
      }
	}

	/*-----------------------------------------------------------------------------------------

									FUNCION IMPRIME UN CLIENTE

	-----------------------------------------------------------------------------------------*/


//Función que imprimirá un cliente por pantalla, el cual ha sido pasado por parametro
//Estará impreso siguiendo unos estandares de calidad
void Agenda::imprimeCliente(Cliente C){

//Declaramos unas estructuras auxiliares para facilitarnos las cosas

Direcciones dir;
Telefonos tlf;
Correos  cor;
Redes redes;
int buscado;

  //Mostramos el nombre
    cout << C.getNombre() << ", "<< C.getApellidos() << "\n";

  //Mostramos el dni
    cout << "-  " << C.getDni()<< "\n";

  //Mostramos las direcciones
    dir = C.getDirecciones();
    cout << "Direccion:\n";
    cout << dir.calle << ", " << dir.puerta << ", " << dir.portal
         << "\n";

  //Mostramos los telefonos
    tlf = C.getTelefonos();
    cout << "Telefonos:\n";
    cout << "- Teléfono fijo:\t" <<tlf.numeroFijo << "\n";
    cout << "- Teléfono móvil:\t" << tlf.numeroMovil1 << "\n";
    cout << "- Teléfono auxiliar:\t" << tlf.numeroMovil2 << "\n";

  //Mostramos los correos
    cor = C.getCorreos();
    cout << "Correos electrónicos:\n";
    cout << "- Gmail:\t" << cor.gmail << "\n";
    cout << "- Hotmail:\t" << cor.hotmail << "\n";
    cout << "- Yahoo:\t" << cor.yahoo << "\n";

  //Mostramos las redes sociales
    redes = C.getRedes();
    cout << "Redes sociales:\n";
    cout << "- Twitter:\t" << redes.twitter << "\n";
    cout << "- Facebook:\t" << redes.facebook << "\n";
    cout << "- Tuenti:\t" << redes.tuenti << "\n";
    cout << "- Linkedin:\t" << redes.linkedin << "\n";

  //Mostramos si el cliente es favorito
  if(C.getFavorito()){
    cout << "Favorito: Sí\n";
  }else
    cout << "Favorito: No\n";

  //Mostramos el numero de veces que se ha buscado dicho cliente
  buscado = C.getMasUsados();
  cout << "Numero de veces buscado: " << buscado << "\n";

  //Mostramos las anotaciones del cliente
  cout << C.getAnotaciones() << "\n";

  //Damos espaciado
  cout << endl << endl;

}


	bool Agenda::hacerCopiaSeguridad(string ficheroCopia){
		char line[20000];

		ifstream fileAgenda;
		ofstream fileCopia;

		fileAgenda.open("Agenda.txt");
		if(fileAgenda.fail()){
			return false;
		}

		fileCopia.open(ficheroCopia.c_str());
		if(!(fileCopia.fail())){
			fileCopia.close();
			remove (ficheroCopia.c_str());
			fileCopia.open(ficheroCopia.c_str());
		}

		while(fileAgenda.getline(line,20000,'\n')){
			fileCopia << line <<endl;
		}

		fileAgenda.close();
		fileCopia.close();
		return true;
	}

	bool Agenda::restaurarCopiaSeguridad(string ficheroCopia){
		char line[20000];

		ofstream fileAgenda;
		ifstream fileCopia;

		fileCopia.open(ficheroCopia.c_str());
		if(fileCopia.fail()){
			return false;
		}

		fileAgenda.open("Agenda.txt");
		if(!(fileAgenda.fail())){
			fileAgenda.close();
			remove ("Agenda.txt");
			fileAgenda.open("Agenda.txt");
		}

		while(fileCopia.getline(line,20000,'\n')){
			fileAgenda << line <<endl;
		}

		fileAgenda.close();
		fileCopia.close();
		return true;
	}


	/*-----------------------------------------------------------------------------------------

									FUNCION PASA DATOS DEL FICHERO A LA LISTA

	-----------------------------------------------------------------------------------------*/

bool Agenda::ficheroALista(){
		char line[256];
		Cliente cl;
		list <Cliente> aux;
		Redes red;
		Direcciones dir;
		Correos cor;
		Telefonos tlf;

		ifstream fileAgenda;

		fileAgenda.open("Agenda.txt");
		if(fileAgenda.fail()){
			return false;
		}

		while(fileAgenda.getline(line,256,',')){
			cl.setNombre(line);

			fileAgenda.getline(line,256,',');
			cl.setApellidos(line);

			fileAgenda.getline(line,256,',');
			cl.setDni(line);

			fileAgenda.getline(line,256,',');
			cl.setAnotaciones(line);

			fileAgenda.getline(line,256,',');
			if(strcmp(line, "si") == 0){
				cl.setFavorito(true);
			}else{
				cl.setFavorito(false);
			}

			fileAgenda.getline(line,256,',');
			cl.setMasUsados(atoi(line));

			fileAgenda.getline(line,256,',');
			red.twitter = line;
			fileAgenda.getline(line,256,',');
			red.facebook = line;
			fileAgenda.getline(line,256,',');
			red.tuenti = line;
			fileAgenda.getline(line,256,',');
			red.linkedin = line;
			cl.setRedes(red);

			fileAgenda.getline(line,256,',');
			dir.calle = line;
			fileAgenda.getline(line,256,',');
			dir.puerta = line;
			fileAgenda.getline(line,256,',');
			dir.portal = line;
			cl.setDirecciones(dir);

			fileAgenda.getline(line,256,',');
			cor.gmail = line;
			fileAgenda.getline(line,256,',');
			cor.hotmail = line;
			fileAgenda.getline(line,256,',');
			cor.yahoo = line;
			cl.setCorreos(cor);

			fileAgenda.getline(line,256,',');
			tlf.numeroFijo = line;
			fileAgenda.getline(line,256,',');
			tlf.numeroMovil1 =line;
			fileAgenda.getline(line,256,'\n');
			tlf.numeroMovil2 = line;
			cl.setTelefonos(tlf);

			aux.push_back(cl);
		}

		setArrayClientes(aux);

		fileAgenda.close();
		return true;

	}


	/*-----------------------------------------------------------------------------------------

									FUNCION PASA LISTA AL FICHERO

	-----------------------------------------------------------------------------------------*/

	bool Agenda::listaAFichero(){
		char line[256];
		Cliente cl;
		Redes red;
		Direcciones dir;
		Correos cor;
		Telefonos tlf;
		list <Cliente> aux;
		aux = getArrayClientes();
		list <Cliente>::iterator pos;
		pos = aux.begin();

		ofstream fileAgenda;

		fileAgenda.open("Agenda.txt");
		if(!(fileAgenda.fail())){
			fileAgenda.close();
			remove ("Agenda.txt");
			fileAgenda.open("Agenda.txt");
		}

		while(pos != aux.end()){
			fileAgenda << (*pos).getNombre() << ',';
			fileAgenda << (*pos).getApellidos() << ',';
			fileAgenda << (*pos).getDni() << ',';
			fileAgenda << (*pos).getAnotaciones() << ',';
			if((*pos).getFavorito()){
				fileAgenda << "si" << ',';
			}else{
				fileAgenda << "no" << ',';
			}
			fileAgenda << (*pos).getMasUsados() << ',';
			red = (*pos).getRedes();
			fileAgenda << red.twitter << ',';
			fileAgenda << red.facebook << ',';
			fileAgenda << red.tuenti << ',';
			fileAgenda << red.linkedin << ',';
			dir = (*pos).getDirecciones();
			fileAgenda << dir.calle << ',';
			fileAgenda << dir.puerta << ',';
			fileAgenda << dir.portal << ',';
			cor = (*pos).getCorreos();
			fileAgenda << cor.gmail << ',';
			fileAgenda << cor.hotmail << ',';
			fileAgenda << cor.yahoo << ',';
			tlf = (*pos).getTelefonos();
			fileAgenda << tlf.numeroFijo << ',';
			fileAgenda << tlf.numeroMovil1 << ',';
			fileAgenda << tlf.numeroMovil2 << '\n';

			pos++;
		}

		fileAgenda.close();
		return true;
	}


Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}
