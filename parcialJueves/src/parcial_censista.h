/*
 * parcial_censista.h
 *
 *  Created on: 19 may. 2022
 *      Author: FRANCO
 */

#ifndef PARCIAL_CENSISTA_H_
#define PARCIAL_CENSISTA_H_
#include "fecha.h"
#include "direcciones.h"

#define LEN_CANT 10
#define ACTIVO 1
#define INACTIVO 0
#define LIBERADO 2
#endif /* PARCIAL_CENSISTA_H_ */

struct {
	int id;
	int idZona;
	char nombre[51];
	char apellido[51];
	int edad;
	int isEmpty;
	int estado; //activo inactivo liberado
	Fechadenacimientos fechadenacimiento;
	Direcciones direccion;
}typedef Censista;
void cargaForzadaCensistas(Censista * censistas);
int darDeBajaCensista(Censista * censistas, int len);
int cargarCensista(Censista *censistas, int len);
int initCensistas(Censista *censistas, int len);
int printCensistas(Censista * list, int len);
int espacioLibreCensistas(Censista * censistas, int len);
int modificarCensista(Censista * censistas, int len);
int idCensistas();
