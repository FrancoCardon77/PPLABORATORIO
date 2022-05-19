/*
 * franBiblioteca.h
 *
 *  Created on: 10 abr. 2022
 *      Author: FRANCO
 */

#ifndef UTN_FUNCIONES_H_
#define UTN_FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_funcionDeMenu(int * pMenuIngresado);
float utn_precioDelVueloConDescuentoTarjetaDeDebito(float variableConPrecioDeVuelo, float descuento);
float utn_precioDelVueloConTarjetaDeCredito(float variableConPrecioDeVuelo, float interes);
float utn_precioDelVueloPagandoConBitCoin(float variableConPrecioDeVuelo, float valorDelBitcoin);
float mostrarPrecioPorValorUnitario(int variableConKilometros, float variableConPrecioDeVuelo);
float laDiferenciaDePrecioEs(float mayor, float menor);
int utn_getFloat(float * pNumeroFlotante, char * mensaje);
int utn_getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos);

/*funciones de la facu*/
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);
int esDescripcion(char* cadena,int longitud);
int getDescripcion(char* pResultado, int longitud);

#endif /* UTN_FUNCIONES_H_ */
