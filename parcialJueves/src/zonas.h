/*
 * zonas.h
 *
 *  Created on: 19 may. 2022
 *      Author: FRANCO
 */

#ifndef ZONAS_H_
#define ZONAS_H_
#include "utn_funciones.h"
#define PENDIENTE 0
#define FINALIZADO 1
//LOCALIDADES
#define CABALLITO 1
#define LANUS 2
#define QUILMES 3
#define AVELLANEDA 4
#define CHINGOLO 5
#define LOMAS 6
#define RECOLETA 7
#define TEREZINO 8
#define OCTUBRE 9
#define WILDE 10

#endif /* ZONAS_H_ */

struct {
	int isEmpty;
	int idZona;
	char calles[4][100];
	char localidad[100];
	int estado; //pendiente0/finalizado1
	int insitu;
	int cargadosVirtualmente;
	int ausentes;
	int idDelCensistaQueCenso;
}typedef Zona;

void cargaForzadaDeZona(Zona * zonas);
int cargarZona(Zona * zonas,int len,int * localidad);
int idZona();
int initZonas(Zona * zonas, int len);
int espacioLibreZonas(Zona * zonas, int len);
int printZonasPendientes(Zona * zonas, int len);
