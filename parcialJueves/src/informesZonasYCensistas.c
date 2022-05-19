/*
 * informesZonasYCensistas.c
 *
 *  Created on: 19 may. 2022
 *      Author: FRANCO
 */
#include "informesZonasYCensistas.h"

/*
 * @brief imprime por pantalla el id de la zonas y el censista responsable de cada zona
 * @param1 para recorrer
 * @param2 el largo de las variables arreglo tipo estructuras
 * @param3 para recorrer
 * @return 0 todo bien -1 ERROR
 */

int printCargaDeDatos(Zona * zonas, int len, Censista * censistas){
    int retorno = -1;

        if (zonas != NULL && len > 0 && censistas != NULL) {

            for (int i = 0; i < len; i++) {
                if (zonas[i].isEmpty == 0 && zonas[i].estado == PENDIENTE) {
                    for(int j = 0; j < len; j++){
                        if(zonas[i].idZona == censistas[j].idZona && censistas[j].estado == ACTIVO){
                            printf("\n Su ID de zona es: [%d] el ID del censista responsable es: [%d] \n estado del censista es: %d\n",zonas[i].idZona,censistas[j].id,censistas[j].estado);
                        }
                    }
                }
            }
        }


    return retorno;
}

/*
 * @brief asigna un censista LIBERADO a una zona para censar si esta zona no tiene a otro censista ACTIVO
 * @param1 para recorrer
 * @param2 el largo de la variables arreglo tipo estructura
 * @param3 para recorrer
 * @return 0 todo bien -1 ERROR
 */
int asignarZonaACensar(Censista* censistas, int len, Zona* zonas)
{
	int retorno = -1;
	int flag = 0;
	int idZona;
	int idDelCensista;
	int zonaPosicion;

	if(censistas != NULL && zonas != NULL && len > 0)
	{	printZonasPendientes(zonas, len);
		utn_getNumero(&idZona, "\nIngrese el ID de zona de la zona a censar: ", "ERROR", 1, 10, 3);
		for(int i=0;i<len;i++)
		{
			if(zonas[i].estado == PENDIENTE && zonas[i].isEmpty == 0 && idZona == zonas[i].idZona)
			{	zonaPosicion = i;
				for(int j=0;j < len;j++)
				{
					if(zonas[i].idZona == censistas[j].idZona && censistas[j].estado == ACTIVO)
					{	retorno = 1;
						flag = 1;
						printf("Ya se está censando la zona");
						break;
					}
				}
			}

		}
		if(flag == 0)
		{
			printCensistas(censistas,len);
			utn_getNumero(&idDelCensista, "\nIngrese el ID del censista para asignar a censar: ", "ERROR", 1, 10, 3);
			for(int i = 0;i<len;i++)
			{
				if(censistas[i].id == idDelCensista && censistas[i].estado == LIBERADO && censistas[i].isEmpty == 0)
				{	retorno = 0;
					censistas[i].idZona = zonas[zonaPosicion].idZona;
					censistas[i].estado = ACTIVO;
					printf("SE ASIGNÓ EL CENSISTA: \n Censista responsable ID: %d \n Apellido y nombre: %s %s ",censistas[i].id, censistas[i].apellido,censistas[i].nombre);
					break;
				}
			}
		}
	}
	return retorno;
}

/*
 * @brief carga los datos indicandole la zona a finalizar si tiene un censista ACTIVO, cambia la zona a estado FINALIZADO tambien liberando al censista
 * recibimos mediante una variable auxiliar de tipo estructura los datos necesarios antes de finalizar el censo
 * @param1 para recorrer
 * @param2 el largo de las variables arreglo tipo estructura
 * @param3 para recorrer
 * @return retorna 0 todo bien -1 ERROR
 */
int cargarDatos(Zona * zonas,int len, Censista * censistas)
{	int retorno = -1;
	int ZonaAFinalizar;
	Zona x;
	if(zonas != NULL && censistas != NULL && len > 0)
	{	printZonasPendientes(zonas, LEN_CANT);
		utn_getNumero(&ZonaAFinalizar, "\nIndique la zona a finalizar por su ID de zona: ","ERROR", 1, 10,99);
		for(int i=0;i<len;i++)
		{
			if(zonas[i].idZona == ZonaAFinalizar && zonas[i].estado == PENDIENTE)
			{
				if(utn_getNumero(&x.insitu, "\nIndique los censados insitu en la zona: ","ERROR", 0, 1000,3)==0)
				{
					if(utn_getNumero(&x.ausentes, "\naIndique los ausentes en la zona: ","ERROR", 0, 1000,3)==0)
					{
						if(utn_getNumero(&x.cargadosVirtualmente, "\nIndique los que censaron virtuales en la zona: ","ERROR", 0, 1000,3)==0)
						{

							for(int j=0;j<len;j++)
							{
								if(censistas[j].idZona == zonas[i].idZona)
								{zonas[i].estado = FINALIZADO;
								censistas[j].estado = LIBERADO;
								zonas[i].idDelCensistaQueCenso = censistas[j].id;
								zonas[i].insitu = x.insitu;
								zonas[i].ausentes = x.ausentes;
								zonas[i].cargadosVirtualmente = x.cargadosVirtualmente;
								censistas[j].idZona = -1;
								printf("ZONA FINALIZADA CON EXITO");
								printZonasPendientes(zonas, LEN_CANT);
								break;
								}
							}

						}
					}
				}


			}
		}
	}
	else{
		printf("ERROR");
	}
	return retorno;
}

/*
 * @brief printea todas las zonas informandonos cada detalle con exactitud en tiempo real para monitorear el proceso de nuestras zonas y sus censistas
 * @param1 para recorrer
 * @param2 el largo de las variables arreglo de tipo estructura
 * @param3 para recorrer
 * @return retorna 0 todo bien -1 error
 */
int printZonasCaseOcho(Zona * zonas, int len, Censista *censistas)
{	int retorno = -1;

	if(zonas != NULL && len>0 && censistas != NULL)
	{	retorno = 0;
		for(int i=0;i<len;i++)
		{
			if(zonas[i].isEmpty == 0 && zonas[i].estado == PENDIENTE && zonas[i].idDelCensistaQueCenso == 0)
			{
				printf("\nID de zona:[%d] \nCALLE 1: %s \nCALLE 2: %s \nCALLE 3: %s \nCALLE 4:%s \n \n Localidad:%s \nEstado de la zona:[ZONA SIN CENSISTA] ",
				zonas[i].idZona,zonas[i].calles[0],zonas[i].calles[1],zonas[i].calles[2],zonas[i].calles[3],zonas[i].localidad);
			}
			else if(zonas[i].isEmpty == 0 && zonas[i].estado == PENDIENTE)
			{
				for(int j=0;j<len;j++)
				{
					if(zonas[i].idZona == censistas[j].idZona && censistas[j].estado == ACTIVO)
					{
						printf("\nID de zona:[%d] \nCALLE 1: %s \nCALLE 2: %s \nCALLE 3: %s \nCALLE 4:%s \n \n Localidad:%s \nEstado de la zona: *ZONA SIENDO CENSADA* \n Censistas responsable [Nombre completo: %s %s  ID [%d]",
						zonas[i].idZona,zonas[i].calles[0],zonas[i].calles[1],zonas[i].calles[2],zonas[i].calles[3],zonas[i].localidad,
						censistas[j].nombre,censistas[j].apellido,censistas[j].id);
					}
				}

			}
			else if(zonas[i].isEmpty == 0 && zonas[i].estado == FINALIZADO)
			{
				for(int j=0;j<len;j++)
				{
				printf("\nID de zona:[%d] \nCALLE 1: %s \nCALLE 2: %s \nCALLE 3: %s \nCALLE 4:%s \n \n Localidad:%s \nEstado de la zona: ZONA FINALIZADA! \n Censistas responsable [Nombre completo: %s %s  ID [%d]",
				zonas[i].idZona,zonas[i].calles[0],zonas[i].calles[1],zonas[i].calles[2],zonas[i].calles[3],zonas[i].localidad,
				censistas[j].nombre,censistas[j].apellido,censistas[j].id);
				}
			}

			}
	}
	return retorno;
}
