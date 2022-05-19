/*
 * zonas.c
 *
 *  Created on: 19 may. 2022
 *      Author: FRANCO
 */
#include "zonas.h"


/*@brief carga datos de manera forzada
 * @param Zona*zonas, carga los datos por puntero a los indices indicado en la creacion de la variable arreglo tipo estructura
 *
 */
void cargaForzadaDeZona(Zona * zonas)
{
	zonas[0].isEmpty = 0;
	zonas[0].estado = PENDIENTE;
	zonas[0].idZona = idZona();
	strncpy(zonas[0].calles[0], "Rodolfo Lopez",sizeof(zonas[0].calles[0]));
	strncpy(zonas[0].calles[1], "Av. Mitre",sizeof(zonas[0].calles[1]));
	strncpy(zonas[0].calles[2], "Larralde",sizeof(zonas[0].calles[2]));
	strncpy(zonas[0].calles[3], "Rodolfo Lopez",sizeof(zonas[0].calles[3]));
	strncpy(zonas[0].localidad,"CABALLITO",sizeof(zonas[0].localidad));
	zonas[0].insitu = 0;
	zonas[0].cargadosVirtualmente = 0;
	zonas[0].ausentes = 0;
	zonas[0].idDelCensistaQueCenso = 0;

	zonas[1].isEmpty = 0;
	zonas[1].estado = PENDIENTE;
	zonas[1].idZona = idZona();
	strncpy(zonas[1].calles[0], "Calchaqui Lopez",sizeof(zonas[1].calles[0]));
	strncpy(zonas[1].calles[1], "Luzzurriaga",sizeof(zonas[1].calles[1]));
	strncpy(zonas[1].calles[2], "Dario suzi",sizeof(zonas[1].calles[2]));
	strncpy(zonas[1].calles[3], "Tronchatora",sizeof(zonas[1].calles[3]));
	strncpy(zonas[1].localidad,"LANUS",sizeof(zonas[1].localidad));
	zonas[1].insitu = 0;
	zonas[1].cargadosVirtualmente = 0;
	zonas[1].ausentes = 0;
	zonas[1].idDelCensistaQueCenso = 0;

	zonas[2].isEmpty = 0;
	zonas[2].estado = PENDIENTE;
	zonas[2].idZona = idZona();
	strncpy(zonas[2].calles[0], "Ruben Pierce",sizeof(zonas[2].calles[0]));
	strncpy(zonas[2].calles[1], "Perni el oni",sizeof(zonas[2].calles[1]));
	strncpy(zonas[2].calles[2], "Jose sito",sizeof(zonas[2].calles[2]));
	strncpy(zonas[2].calles[3], "Esteban kito",sizeof(zonas[2].calles[3]));
	strncpy(zonas[2].localidad,"QUILMES",sizeof(zonas[2].localidad));
	zonas[2].insitu = 0;
	zonas[2].cargadosVirtualmente = 0;
	zonas[2].ausentes = 0;
	zonas[2].idDelCensistaQueCenso = 0;

	zonas[3].isEmpty = 0;
	zonas[3].estado = PENDIENTE;
	zonas[3].idZona = idZona();
	strncpy(zonas[3].calles[0], "Koku",sizeof(zonas[3].calles[0]));
	strncpy(zonas[3].calles[1], "Kohan",sizeof(zonas[3].calles[1]));
	strncpy(zonas[3].calles[2], "Joten",sizeof(zonas[3].calles[2]));
	strncpy(zonas[3].calles[3], "Beyeta",sizeof(zonas[3].calles[3]));
	strncpy(zonas[3].localidad,"AVELLANEDA",sizeof(zonas[3].localidad));
	zonas[3].insitu = 0;
	zonas[3].cargadosVirtualmente = 0;
	zonas[3].ausentes = 0;
	zonas[3].idDelCensistaQueCenso = 0;

	zonas[4].isEmpty = 0;
	zonas[4].estado = PENDIENTE;
	zonas[4].idZona = idZona();
	strncpy(zonas[4].calles[0], "Labrador",sizeof(zonas[4].calles[0]));
	strncpy(zonas[4].calles[1], "Caniche",sizeof(zonas[4].calles[1]));
	strncpy(zonas[4].calles[2], "Bulldog",sizeof(zonas[4].calles[2]));
	strncpy(zonas[4].calles[3], "Terrier",sizeof(zonas[4].calles[3]));
	strncpy(zonas[4].localidad,"CHINGOLO",sizeof(zonas[4].localidad));
	zonas[4].insitu = 0;
	zonas[4].cargadosVirtualmente = 0;
	zonas[4].ausentes = 0;
	zonas[4].idDelCensistaQueCenso = 0;
}

/*
 * @brief Carga una zona elijiendo 4 calles y 1 localidad
 * @param1 envia los datos recibidos por el usuario desde una variable de tipo estructura auxiliar
 * @param2 el largo de la variable tipo estructura
 * @param3 el array de localidades tipo entero
 * @return 0 todo bien -1 todo mal
 */
int cargarZona(Zona * zonas,int len,int * localidad)
{
	int retorno = -1;
		int respuesta = 1;
		int index;
		int localidades;
		Zona x;

		if (zonas != NULL && len > 0) {
			do {
				if (respuesta == 1) {
							if (utn_getNombre(x.calles[0], 51,
									"\nIngrese el nombre de la calle 1: ",
									" Error.", 3) == 0) {
								if (utn_getNombre(x.calles[1], 51,
										"\nIngrese el nombre de la calle 2: ",
										" Error.", 3) == 0) {

									if (utn_getNombre(x.calles[2], 51,
											"\nIngrese el nombre de la calle 3: ",
											" Error.", 3) == 0) {

										if (utn_getNombre(x.calles[3], 51,
												"\nIngrese el nombre de la calle 4: ",
												" Error.", 3) == 0) {
											if(utn_getNumero(&localidades,"\nElija una localidad 1)CABALLITO 2)LANUS 3)QUILMES 4)AVELLANEDA 5)CHINGOLO 6)LOMAS 7)RECOLETA 8)TEREZINO 9)OCTUBRE 10)WILDE "," Error.", 1,10, 3)==0){
																switch(localidad[localidades])
																{
																case 1:strncpy(x.localidad,"CABALLITO",sizeof(x.localidad));
																	break;
																case 2:strncpy(x.localidad,"LANUS",sizeof(x.localidad));
																	break;
																case 3:strncpy(x.localidad,"QUILMES",sizeof(x.localidad));
																	break;
																case 4:strncpy(x.localidad,"AVELLANEDA",sizeof(x.localidad));
																	break;
																case 5:strncpy(x.localidad,"CHINGOLO",sizeof(x.localidad));
																	break;
																case 6:strncpy(x.localidad,"LOMAS",sizeof(x.localidad));
																	break;
																case 7:strncpy(x.localidad,"RECOLETA",sizeof(x.localidad));
																	break;
																case 8:strncpy(x.localidad,"TEREZINO",sizeof(x.localidad));
																	break;
																case 9:strncpy(x.localidad,"OCTUBRE",sizeof(x.localidad));
																	break;
																case 10:strncpy(x.localidad,"WILDE",sizeof(x.localidad));
																	break;
																}
																x.idZona = idZona();
																x.isEmpty = 0;
																x.idDelCensistaQueCenso = 0;
																index = espacioLibreZonas(zonas, len);
																zonas[index] = x;
																retorno = 0;
											}
										}
									}
								}
							}
						}
				utn_getNumero(&respuesta,"\nDesea cargar otra zona: 1 para ingresar otro censista - 2 para ir al menu principal "," Error.", 1,2, 3);
					}
			while (respuesta == 1);
				}
		return retorno;

}

/*
 * @brief asigna un id de zona a la zona de forma ascendente ej(1,2,3,4...)
 * @return devuelve el incremento de idzona
 */
int idZona()
{	int static idZona = 0;
	idZona++;
	return idZona;
}

/*
 * @brief encuentra un indice libre con su valor isEmpty en 1
 * @param1 Zona*zonas, utilizado para recorrer y encontrar un espacio libre
 * @param2 el largo de la variable tipo estructura
 * @return devuelve el indice con el espacio libre
 */
int espacioLibreZonas(Zona * zonas, int len)
{
	int retorno = -1;
	if(zonas != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(zonas[i].isEmpty == 1 )
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/*
 * @brief muestra las zonas con estado pendiente y sus datos en detalle
 * @param1 se utiliza para recorrer con un for
 * @param2 el largo de la variable tipo estructura
 * @return devuelve 0 si esta todo bie, o -1 si fallo
 */
int printZonasPendientes(Zona * zonas, int len)
{	int retorno = -1;

	char estado[51] = "PENDIENTE";

	if(zonas != NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(zonas[i].isEmpty == 0 && zonas[i].estado == PENDIENTE)
			{	retorno = 0;
				printf("\nID de zona:[%d] \nCALLE 1: %s \nCALLE 2: %s \nCALLE 3: %s \nCALLE 4:%s \nLocalidad:%s \nEstado de la zona:%s",zonas[i].idZona,zonas[i].calles[0],zonas[i].calles[1],zonas[i].calles[2],zonas[i].calles[3],zonas[i].localidad,estado);
			}

		}
	}
	return retorno;
}

/*
 * @brief pone el valor de la variable isEmpty en 1 en todas las posiciones de las variables tipo estructura Zona
 * @param1 recorre las variables de tipo estructura Zona
 * @param 2 el largo de la variable tipo estructura
 * @return 0 todo bien -1 todo mal
 */
int initZonas(Zona * zonas, int len){
	int retorno = -1;

	if(zonas != NULL && len > 0)
	{
		for(int i=0;i <len;i++)
		{	retorno= 0;
			zonas[i].isEmpty = 1;
		}
	}
	return retorno;
}
