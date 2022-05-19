/*
 * parcial_censista.c
 *
 *  Created on: 19 may. 2022
 *      Author: FRANCO
 */
#include "parcial_censista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @brief da de baja un censista eligiendolo por su ID pasando su estado a INACTIVO solo si esta LIBERADO y luego pregunta si quiere ser borrado completamente pasando su isEmpty a 1
 * @param1 para recorrer
 * @param2 el largo de la variable arreglo de tipo estructura
 * @return 0 todo bien -1 error
 */
int darDeBajaCensista(Censista * censistas, int len) {
	int retorno = -1;
	int idAEliminar;
	int respuesta;

	if(censistas != NULL && len > 0)
	{
	printCensistas(censistas, len);
	utn_getNumero(&idAEliminar,"\nIngrese el ID a dar de baja del Censista: ", "Error", 1,len, 3);
	for(int i=0;i<len;i++)
	{
		if(censistas[i].id == idAEliminar && censistas[i].estado == LIBERADO)
		{
			censistas[i].estado = INACTIVO;
			if(censistas[i].estado == INACTIVO)
			{
				utn_getNumero(&respuesta,"\n¿DESEA ELIMINAR AL CENSISTA COMPLETAMENTE? 1 para si - 2 para no ", "Error", 1,2, 3);
				if(idAEliminar == 1)
				{
					censistas[i].isEmpty = 1;
					printf("El Censista ha sido eliminado completamente.");
					printCensistas(censistas, len);
					break;
				}
			}
		}
	  }
	}


	return retorno;
}
/*
 * @brief crea un censista con todos sus datos, autoasignadole un id de forma ascendente ej(1,2,3,4...)
 * @param1 para recorrer
 * @param2 el largo de la variable arreglo de tipo estructura
 * @return 0 todo bien -1 error
 */

int cargarCensista(Censista *censistas, int len) {

	int retorno = -1;
	int respuesta = 1;
	int index;

	Censista x;

	if (censistas != NULL && len > 0) {
		do {
			if (respuesta == 1) {
						if (utn_getNombre(x.nombre, 51,
								"\nIngrese el nombre del censista: ",
								" Error. ", 3) == 0) {
							if (utn_getNombre(x.apellido, 51,
									"\nIngrese el apellido del censista: ",
									" Error. ", 3) == 0) {

								if (utn_getNumero(&x.edad,
										"\nIngrese la edad del censista: ",
										" Error. ", 18, 60, 3) == 0) {



										if (utn_getNumero(
												&x.fechadenacimiento.dia,
												"\nIngrese el día de nacimiento: ",
												" Error.", 1, 31, 3) == 0) {
											if (utn_getNumero(
													&x.fechadenacimiento.mes,
													"\nIngrese el mes de nacimiento: ",
													" Error.", 1, 12, 3) == 0) {
												if (utn_getNumero(
														&x.fechadenacimiento.anio,
														"\nIngrese el año de nacimiento: ",
														" Error.", 1960, 2004,
														3) == 0) {
													if (utn_getNombre(
															x.direccion.calle,
															51,
															"\nIngrese el nombre de la calle del censista: ",
															" Error. ", 3)
															== 0) {
														if (utn_getNumero(
																&x.direccion.altura,
																"\nIngrese la altura de la calle: ",
																" Error.", 01,
																15000, 3) == 0) {
															x.id = idCensistas();
															x.isEmpty = 0;
															index = espacioLibreCensistas(censistas, len);
															censistas[index] = x;
															censistas[index].estado = LIBERADO;
															retorno = 0;

													}
												}
											}
										}
									}
								}
							}
						}
					}
			utn_getNumero(&respuesta,"\nDesea cargar otro censista: 1 para ingresar otro censista - 2 para ir al menu principal "," Error.", 1,2, 3);
				}
		while (respuesta == 1);
			}
	return retorno;
}

/*
 * @brief inicializa todas las posiciones de la variable arreglo de tipo estructura cambiandole su variable anidada de la estructura isEmpty a 1
 * @param1 para recorrer
 * @param2 el largo de la variable de arreglo de tipo estructura
 * @return 0 todo bien -1 error
 */

int initCensistas(Censista *censistas, int len) {

	for (int i = 0; i < len; i++) {
		censistas[i].isEmpty = 1;
	}

	return 0;
}

/*
 * @brief imprime por pantalla todos los censistas con su isEmpty en valor 0
 * @param1 para recorrer
 * @param2 el largo de la variable arreglo de tipo estructura
 * @return 0 todo bien -1 error
 */
int printCensistas(Censista * censistas, int len)
{
	int retorno = -1;

	if(censistas != NULL && len >0)
	{	retorno = 0;
		for(int i=0; i<len;i++)
		{	if(censistas[i].isEmpty == 0)
			{
			printf("\nID: [%d] \n\nNombre: %s \nApellido: %s \nEdad: %d \nEstado: %d \nFecha De Nacimiento:%d/%d/%d  \nDirección: %s %d \n\n",
					censistas[i].id, censistas[i].nombre,
					censistas[i].apellido, censistas[i].edad,
					censistas[i].estado, censistas[i].fechadenacimiento.dia,
					censistas[i].fechadenacimiento.mes,censistas[i].fechadenacimiento.anio,
					censistas[i].direccion.calle,censistas[i].direccion.altura);
			}
		}
	}

	return retorno;
}

/*
 * @brief encuentra una posicion libre recorriendo la variable arreglo de tipo estructura hasta encontrar un isEmpty en 1 y devolviendonos su posicion por return
 * @param1 para recorrer
 * @param2 el largo de la variable arreglo de tipo estructura
 * @return 0 todo bien -1 todo mal
 */
int espacioLibreCensistas(Censista * censistas, int len)
{
	int retorno = -1;
	if(censistas != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(censistas[i].isEmpty == 1 )
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*
 * @brief modifica un censista buscandolo por el ID que le indiquemos
 * @param1 para recorrer
 * @param2 el largo de la variable arreglo de tipo estructura
 * @return 0 todo bien -1 error
 */
int modificarCensista(Censista * censistas, int len) {
	int retorno = -1;
	char auxName[51];
	char auxLastName[51];
	int auxEdad;
	int respuesta;
	int flagModificacion = 0;
	int k;
	int numeroFechaAModificar;
	int idAmodificar;


	if (censistas != NULL && len > 0) {
		printCensistas(censistas, len);
		utn_getNumero(&idAmodificar,"\n¿Que Censista desea modificar? Ingrese ID: ", "Error", 1,10, 3);
		retorno = 1;
		for (int i = 0; i < len; i++) {
			if (censistas[i].id == idAmodificar && censistas[i].isEmpty == 0) {
				printf("\nEste es el Censista a modificar. Nombre: %s \n Apellido: %s \n Edad: %d \n Fecha de nacimiento. dia:%d mes:%d año:%d \n",censistas[i].nombre, censistas[i].apellido, censistas[i].edad,censistas[i].fechadenacimiento.dia,censistas[i].fechadenacimiento.mes,censistas[i].fechadenacimiento.anio);
				utn_getNumero(&respuesta,
						"¿Desea modificarlo? 1 para si 2 para no: ", "Error", 1,
						2, 3);
				k = i;
				if (respuesta == 1) {
					do {
						utn_getNumero(&respuesta,
								"\n 1 para modificar el nombre - 2 para modificar el apellido - 3 para modificar la edad - 4 para modificar el tipo de fecha 5 - CANCELAR",
								"Error", 1, 6, 3);
						switch (respuesta) {
						case 1:
							utn_getNombre(auxName, 51,
									"\nElija el nuevo nombre: ",
									"\nError ingrese nuevamente el nombre: ",
									3);
							strcpy(censistas[i].nombre, auxName);
							flagModificacion = 1;
							break;
						case 2:
							utn_getNombre(auxLastName, 51,
									"\nElija el nuevo apellido: ",
									"\nError ingrese nuevamente el apellido: ",
									3);
							strcpy(censistas[i].apellido, auxLastName);
							flagModificacion = 1;
							break;
						case 3:
							utn_getNumero(&auxEdad,
									"\nIngrese la nueva edad: ",
									"\nError ingrese nuevamente el precio", 0,
									60, 3);
							censistas[i].edad = auxEdad;
							flagModificacion = 1;
							break;
						case 4:utn_getNumero(&numeroFechaAModificar,"\n¿Que fecha desea editar?: 1 dia - 2 mes - 3 año ","\nERROR", 1,60, 3);
								switch(auxEdad)
								{
								case 1:utn_getNumero(&censistas[i].fechadenacimiento.dia,"\nElija el numero del dia a modificar","\nERROR", 1,31, 3);
									break;
								case 2:utn_getNumero(&censistas[i].fechadenacimiento.mes,"\nElija el numero del mes a modificar","\nERROR", 1,12, 3);
									break;
								case 3:utn_getNumero(&censistas[i].fechadenacimiento.anio,"\nElija el numero del anio a modificar","\nERROR", 1960,2004, 3);
									   utn_getNumero(&censistas[i].edad,"\nIngrese su nueva edad.","\nERROR", 1,60, 3);
									break;

								}
							flagModificacion = 1;
							break;
						case 5:
						flagModificacion = 0;
						break;


						}
						if (flagModificacion == 1) {
							utn_getNumero(&respuesta,
									"\n¿Desea modificar otro dato? 1 para si 2 para no: ",
									"\n Error", 1, 2, 3);
						} else {
							respuesta = 0;
						}
					} while (respuesta == 1);
				} else if (flagModificacion == 0) {
					printf("\n No se hicieron cambios");
				}

			}
		}
		printf(
				"\nID: %d \nNombre: %s \nApellido: %s \nEdad: %d \nEstado: %d \nFecha de nacimiento: %d/%d/%d",
				censistas[k].id, censistas[k].nombre, censistas[k].apellido, censistas[k].edad,
				censistas[k].estado, censistas[k].fechadenacimiento.dia, censistas[k].fechadenacimiento.mes,censistas[k].fechadenacimiento.anio);

	} else {
		printf("\nNo se encontro el id a modificar");
		retorno = -1;
	}

	return retorno;
}
/*
 * @brief auto incrementa el id para devolver el valor por return y asignarle a nuestro censista recien creado
 */
int idCensistas()
{
	static int id = 0;
	id++;
	return id;
}
/*
 * @brief carga datos forzados de censistas
 * @param1 para recorrer
 */
void cargaForzadaCensistas(Censista * censistas)
{
		strncpy(censistas[0].nombre, "Juan", sizeof(censistas[0].nombre));
		strncpy(censistas[0].apellido, "Perez",sizeof(censistas[0].apellido));
		censistas[0].id = idCensistas();
		censistas[0].edad = 22;
		censistas[0].estado = LIBERADO;
		censistas[0].isEmpty = 0;
		censistas[0].fechadenacimiento.dia = 10;
		censistas[0].fechadenacimiento.mes = 9;
		censistas[0].fechadenacimiento.anio = 2000;
		strncpy(censistas[0].direccion.calle, "tefaltacalle",sizeof(censistas[0].direccion.calle));
		censistas[0].direccion.altura = 2057;
		censistas[0].idZona = -1;

		strncpy(censistas[1].nombre, "Gaston",sizeof(censistas[1].nombre));
		strncpy(censistas[1].apellido, "Argibay",sizeof(censistas[1].apellido));
		censistas[1].id = idCensistas();
		censistas[1].edad = 30;
		censistas[1].estado = LIBERADO;
		censistas[1].isEmpty = 0;
		censistas[1].fechadenacimiento.dia = 10;
		censistas[1].fechadenacimiento.mes = 9;
		censistas[1].fechadenacimiento.anio = 1992;
		strncpy(censistas[1].direccion.calle, "Av.Valorant",sizeof(censistas[1].direccion.calle));
		censistas[1].direccion.altura = 666;
		censistas[1].idZona = -1;

		strncpy(censistas[2].nombre, "Octavio",sizeof(censistas[2].nombre));
		strncpy(censistas[2].apellido, "Villegas",sizeof(censistas[2].apellido));
		censistas[2].id = idCensistas();
		censistas[2].edad = 30;
		censistas[2].estado = LIBERADO;
		censistas[2].isEmpty = 0;
		censistas[2].fechadenacimiento.dia = 10;
		censistas[2].fechadenacimiento.mes = 9;
		censistas[2].fechadenacimiento.anio = 1992;
		strncpy(censistas[2].direccion.calle, "Mediocre",sizeof(censistas[2].direccion.calle));
		censistas[2].direccion.altura = 514;
		censistas[2].idZona = -1;

		strncpy(censistas[3].nombre, "Miguel",sizeof(censistas[3].nombre));
		strncpy(censistas[3].apellido, "Diaz",sizeof(censistas[3].apellido));
		censistas[3].id = idCensistas();
		censistas[3].edad = 50;
		censistas[3].estado = LIBERADO;
		censistas[3].isEmpty = 0;
		censistas[3].fechadenacimiento.dia = 10;
		censistas[3].fechadenacimiento.mes = 9;
		censistas[3].fechadenacimiento.anio = 1972;
		strncpy(censistas[3].direccion.calle, "Cobra Kai",sizeof(censistas[3].direccion.calle));
		censistas[3].direccion.altura = 4;
		censistas[3].idZona = -1;

		strncpy(censistas[4].nombre, "Lionel",sizeof(censistas[4].nombre));
		strncpy(censistas[4].apellido, "Messi",sizeof(censistas[4].apellido));
		censistas[4].id = idCensistas();
		censistas[4].edad = 30;
		censistas[4].estado = LIBERADO;
		censistas[4].isEmpty = 0;
		censistas[4].fechadenacimiento.dia = 10;
		censistas[4].fechadenacimiento.mes = 9;
		censistas[4].fechadenacimiento.anio = 1992;
		strncpy(censistas[4].direccion.calle, "Cardon",sizeof(censistas[4].direccion.calle));
		censistas[4].direccion.altura = 4;
		censistas[4].idZona = -1;
}
