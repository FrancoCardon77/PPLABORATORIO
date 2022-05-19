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

int main(void) {
	setbuf(stdout, NULL);

	Censista censistas[LEN_CANT];
	Zona zonas[LEN_CANT];

	int localidad[11] = {0,CABALLITO,LANUS,QUILMES,AVELLANEDA,CHINGOLO,LOMAS,RECOLETA,TEREZINO,OCTUBRE,WILDE};

	int opcionMenu;

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
						"9. SALIR\n"
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
		case 9:
			printf("Adios.");
			break;
		case 10: cargaForzadaCensistas(censistas);
			break;
		case 11: cargaForzadaDeZona(zonas);
			break;
		}
	} while (opcionMenu != 9);

	return 0;
}




