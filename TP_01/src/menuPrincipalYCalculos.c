/*
 * menuPrincipalYCalculos.c
 *
 *  Created on: 12 abr. 2022
 *      Author: W. Neira
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menuPrincipalYCalculos.h"

int menuPrincipal() {
	int opcion;
	int cant;

	printf("1- Ingresar kilometros \n");
	printf("2- Ingresar Precio de Vuelos \n");
	printf("3- Calcular todos los costos \n");
	printf("4- Informar Resultados \n");
	printf("5- Carga forzada de datos \n");
	printf("6- Salir \n\n");

	printf("seleccione la opcion deseada: \n");
	fflush(stdin);
	cant = scanf("%d", &opcion);
	if (cant == 0) {
		opcion = 7;
	}

	return opcion;
}

int ingresoPrecioVuelos(char *mensaje, char *mensajeError) {
	float cant;
	int input;

	printf("%s", mensaje);
	fflush(stdin);
	input = scanf("%f", &cant);
	while (input == 0 || cant < 0) {
		printf("%s", mensajeError);
		printf("%s", mensaje);
		fflush(stdin);
		input = scanf("%f", &cant);
	}

	return cant;

}

void informeDeResultados(float precioLatam, float precioAA,
		float precioDebitoLatam, float precioDebitoAA, float precioCreditoLatam,
		float precioCreditoAA, float precioBtcLatam, float precioBtcAA,
		float precioUnitarioLatam, float precioUnitarioAA, float diferencia,
		float kms) {
	printf("KMs Ingresados: %.2f km \n\n", kms);
	printf("Precio Aerolineas: $ %.2f \n", precioAA);
	printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebitoAA);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", precioCreditoAA);
	printf("c) Precio pagando con bitcoins: %.5f BTC \n", precioBtcAA);
	printf("d) Mostrar precio Unitario: $ %.2f \n\n", precioUnitarioAA);
	printf("Precio Latam: $ %.2f \n", precioLatam);
	printf("a) Precio con tarjeta de debito: $ %.2f \n", precioDebitoLatam);
	printf("b) Precio con tarjeta de credito: $ %.2f \n", precioCreditoLatam);
	printf("c) Precio pagando con bitcoins: %.5f BTC \n", precioBtcLatam);
	printf("d) Mostrar precio Unitario: $ %.2f \n\n", precioUnitarioLatam);
	printf("La diferencia de precio es: $ %.2f \n\n", diferencia);
}

float ingresoDeKm() {
	float km;
	int cant;

	printf("Ingrese los kilometros del vuelo: \n");
	fflush(stdin);
	cant = scanf("%f", &km);
	while (km <= 0 || cant == 0) {
		printf("ERROR! ingresar nuevamente los kilometros: \n");
		fflush(stdin);
		cant = scanf("%f", &km);
	}
	return km;
}

void informarNoEsNumero()
{
    printf("La opcion elegida no es un numero. Elija uno de los numeros del menu.\n");
}

float pagoConDebito(float precio) {
	float precioDebito;
	precioDebito = precio - (precio * 10 / 100);
	return precioDebito;
}

float pagoConCredito(float precio) {
	float precioCredito;
	precioCredito = precio + (precio * 25 / 100);
	return precioCredito;
}

float pagoConBtc(float precio) {
	float precioBtc;
	precioBtc = precio / 4647510.50;
	return precioBtc;
}

float precioXKm(float precio, float km) {
	float precioUnitario;
	precioUnitario = precio / km;
	return precioUnitario;
}




