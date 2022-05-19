/*
 ============================================================================
 Name        : parcialJueves.c
 Author      : franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_funciones.h"
#include "informesZonasYCensistas.h"
#define LEN_CANT 10

int LocalidadConMasAusentes(Zona * zonas, int len);
int cantidadCensistasActivoConZonaPendiente(Censista * censistas,int len,Zona * zonas);
int informarElCensistaZonaMascensada(Zona * zonas,int len, Censista * censistas);
int promedioDeCensos(Zona * zonas, int len, Censista * censistas);

int main(void) {
	setbuf(stdout, NULL);

	Censista censistas[LEN_CANT];
	Zona zonas[LEN_CANT];

	int localidad[11] = {0,CABALLITO,LANUS,QUILMES,AVELLANEDA,CHINGOLO,LOMAS,RECOLETA,TEREZINO,OCTUBRE,WILDE};
	int respuestaInforme;
	int opcionMenu;
	int cantidadCensistasActivoConZonaPendientes = 0;

	initCensistas(censistas, LEN_CANT);

	initZonas(zonas, LEN_CANT);

	do {
		if (utn_getNumero(&opcionMenu,

				"\n*****************************MENU PRINCIPAL*****************************\n\n"
						"1. Carga censista: \n"
						"2. Modificar censita: \n"
						"3. Dar de baja censista: \n"
						"4. Cargar zona: \n"
						"5. Asignar zona a censar: \n"
						"6. Carga de datos: \n"
						"7. Mostrar censistas: \n"
						"8. Mostrar zonas: \n"
						"9. Informes\n"
						"10. Carga forzada Censistas\n"
						"11. Carga forzada de zonas\n"
						"\nElija una opcion: ",

				"\nError opcion invalida", 1, 11, 2) == 0) {

		}
		switch (opcionMenu) {
		case 1:
			cargarCensista(censistas, LEN_CANT);
			break;
		case 2:
			modificarCensista(censistas, LEN_CANT);
			break;
		case 3:
			darDeBajaCensista(censistas, LEN_CANT);
			break;
		case 4:
			cargarZona(zonas,LEN_CANT,localidad);
			break;
		case 5:
			asignarZonaACensar(censistas,LEN_CANT,zonas);
			break;
		case 6:
			cargarDatos(zonas,LEN_CANT,censistas);
			break;
		case 7:
			printCensistas(censistas, LEN_CANT);
			break;
		case 8:
			printZonasCaseOcho(zonas,LEN_CANT,censistas);
			break;
		case 9: if(utn_getNumero(&respuestaInforme, "\nQue informe desea obtener  1)Informar cantidad de censistas en estado Activo con zona Pendiente. \n2)Informar nombre de localidad con más casas ausentes.) ","ERROR",1,4,3)==0)
		{
			switch(respuestaInforme)
			{
			case 1:cantidadCensistasActivoConZonaPendientes = cantidadCensistasActivoConZonaPendiente(censistas,LEN_CANT, zonas);
					printf("La cantidad de censistas ACTIVOS con zonas pendientes son :%d",cantidadCensistasActivoConZonaPendientes);
					break;
			case 2:LocalidadConMasAusentes(zonas, LEN_CANT);
					break;
			case 3:informarElCensistaZonaMascensada(zonas,LEN_CANT, censistas);
				    break;
			case 4:promedioDeCensos(zonas, LEN_CANT,censistas);
					break;
			}
		}

			break;
		case 10: cargaForzadaCensistas(censistas);
			break;
		case 11: cargaForzadaDeZona(zonas);
			break;
		}
	} while (opcionMenu != 9);

	return 0;
}

int LocalidadConMasAusentes(Zona * zonas, int len)
{	int retorno = -1;
	int flag = 0;
	char LocalidadConMasAusentes[150];
	int cantidadDeAusentes = 0;

	if(zonas != NULL && len > 0)
	{
			for(int i=0;i<len;i++)
			{
				if(zonas[i].ausentes > 0 && flag == 0)
				{	retorno = 0;
					cantidadDeAusentes = zonas[i].ausentes;
					strcpy(LocalidadConMasAusentes, zonas[i].localidad);
					flag = 1;
				}
			}
			for(int j=0;j<len;j++)
			{
				if(zonas[j].ausentes > cantidadDeAusentes)
				{	retorno = 0;
					strcpy(LocalidadConMasAusentes, zonas[j].localidad);
					cantidadDeAusentes = zonas[j].ausentes;
				}
			}
	}
	printf("\nLa zona con mas ausentes es: %s y su cantidad de ausentes son: %d",LocalidadConMasAusentes,cantidadDeAusentes);
   return retorno;
}

int cantidadCensistasActivoConZonaPendiente(Censista * censistas,int len,Zona * zonas)
{
  int contadorDeCensistasActivosConZonaPendiente;

	if(censistas!= NULL && len > 0 && zonas != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(censistas[i].estado == ACTIVO)
			{
				for(int j=0;j<len;j++)
				{
					if(zonas[j].estado == PENDIENTE)
					{
						contadorDeCensistasActivosConZonaPendiente ++;
					}
				}
			}
		}
	}

	return contadorDeCensistasActivosConZonaPendiente;
}

//Informar el censista cuya zona fue la más censada (total censados presencial y virtual)
int informarElCensistaZonaMascensada(Zona * zonas,int len, Censista * censistas)
{ int retorno =-1;
  Zona zonaMasCensada;
  int flag = 0;
	if(zonas != NULL && len > 0 && censistas != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(zonas[i].insitu > 0 && zonas[i].cargadosVirtualmente >0 && flag ==0)
			{
				flag = 1;
				zonaMasCensada = zonas[i];

			}
		}
		for(int j=0;j<len;j++)
		{
			if(zonas[j].ausentes > zonaMasCensada.ausentes && zonas[j].cargadosVirtualmente > zonaMasCensada.cargadosVirtualmente)
			{
				zonaMasCensada = zonas[j];
			}
		}
		for(int k=0;k<len;k++)
		{
			if(zonaMasCensada.idDelCensistaQueCenso == censistas[k].id )
			{	retorno = 0;
				printf("\nDatos del Censista cuya zona fue mas censada ID:[%d]  Nombre completo: %s %s \n la zona con mas censados es: IDZona [%d] Localidad:%s con censados presentes:%d y censados virtual:%d\n",
						censistas[k].id,censistas[k].apellido,censistas[k].nombre,zonaMasCensada.idZona,zonaMasCensada.localidad,zonaMasCensada.insitu,zonaMasCensada.cargadosVirtualmente);
				break;
			}
		}
	}
	return retorno;
}

//Informar el promedio de censos por censista/zona.
int promedioDeCensos(Zona * zonas, int len, Censista * censistas)
{ int retorno = -1;
  int zonasTotal;
  int personasTotalCensadas;
  int promedioPersonasCensadas;

	if(zonas != NULL && len > 0  && censistas != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(censistas[i].estado == LIBERADO)
			{
				for(int j=0;j<len;j++)
				{
					if(censistas[i].id == zonas[j].idDelCensistaQueCenso  && zonas[j].estado == FINALIZADO)
					{
						zonasTotal++;
						personasTotalCensadas = zonas[j].cargadosVirtualmente + zonas[j].insitu;
					}
					if(j == len-1)
					{
						promedioPersonasCensadas = personasTotalCensadas/zonasTotal;
						printf("\nCensista ID[%d] Nombre completo: %s %s SU PROMEDIO DE CENSO ES: %d CON UN TOTAL DE ZONAS CENSADAS DE: %d\n",censistas[i].id,censistas[i].apellido,censistas[i].nombre,promedioPersonasCensadas,zonasTotal);


					}
				}
			}
		}
	}
	return retorno;
}

