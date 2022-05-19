/*
 * informesZonasYCensistas.h
 *
 *  Created on: 19 may. 2022
 *      Author: FRANCO
 */

#ifndef INFORMESZONASYCENSISTAS_H_
#define INFORMESZONASYCENSISTAS_H_

#include "parcial_censista.h"
#include "zonas.h"
#include "utn_funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int printZonasCaseOcho(Zona * list, int len,Censista * censistas);
int printCargaDeDatos(Zona * zonas, int len, Censista * censista);
int asignarZonaACensar(Censista* censistas, int len, Zona* zonas);
int cargarDatos(Zona * zonas,int len, Censista * censistas);

#endif /* INFORMESZONASYCENSISTAS_H_ */
