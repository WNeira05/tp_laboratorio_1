/*
 ============================================================================
 Name        : TP_01.c
 Author      : W. Neira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menuPrincipalYCalculos.h"


int main()
{
	setbuf(stdout, NULL);
	int	flagKm = 0;
	int	flagPrecioVuelos = 0;
	int flagCalculos = 0;
	float km= 0;
	float precioAA = 0;
	float precioDebitoAA;
	float precioCreditoAA;
	float precioBtcAA;
	float precioUnitarioAA;
	float precioLatam = 0;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBtcLatam;
	float precioUnitarioLatam;
	float diferencia;
	char salir;

	do{
		switch(menuPrincipal())
		{
			case 1:
				km = ingresoDeKm();
				flagKm = 1;
			break;
			case 2:
				if(flagKm == 1)
				{
					precioAA = ingresoPrecioVuelos("Ingrese el precio de Aerolineas Argentinas: \n", "ATENCION! El valor ingresado es incorrecto\n\n" );
					precioLatam = ingresoPrecioVuelos("Ingrese el precio de Latam: \n", "ATENCION! El valor ingresado es incorrecto\n\n" );

				    printf("precio Aerolineas Argentinas: $%.2f\n", precioAA);
				    printf("precio Latam: $%.2f\n", precioLatam);

				    flagPrecioVuelos = 1;
				}
				else
				{
					printf("ATENCION. Para ingresar los precios de cada aerolinea, primero se debe ingresar los Kms en la opcion 1. \n");
				}
			break;
			case 3:
				if(flagKm == 1 && flagPrecioVuelos == 1)
				{
					precioDebitoLatam = pagoConDebito(precioLatam);
					precioDebitoAA = pagoConDebito(precioAA);
					precioCreditoLatam = pagoConCredito(precioLatam);
					precioCreditoAA = pagoConCredito(precioAA);
					precioBtcLatam = pagoConBtc(precioLatam);
					precioBtcAA = pagoConBtc(precioAA);
					precioUnitarioLatam = precioXKm(precioLatam, km);
					precioUnitarioAA = precioXKm(precioAA, km);
					diferencia = precioLatam - precioAA;
					printf("Los calculos fueron realizados correctamente, para poder verlos seleccione la opcion 4 en el menu.  \n");

					flagCalculos = 1;
				}
				else if(flagKm == 1 && flagPrecioVuelos == 0)
				{
					printf("Error. Antes de realizar los calculos se debe ingresar el precio de los vuelos. \n");
				}
				else if(flagKm == 0 && flagPrecioVuelos == 1)
				{
					printf("Error. Antes de realizar los calculos se debe ingresar los Kms. \n");
				}
				else
				{
					printf("Error. Antes de realizar los calculos se debe ingresar los Kms y el precios de los vuelos.\n");
				}
			break;
			case 4:
				if(flagCalculos == 1)
				{
					informeDeResultados(precioLatam, precioAA, precioDebitoLatam, precioDebitoAA, precioCreditoLatam, precioCreditoAA, precioBtcLatam, precioBtcAA, precioUnitarioLatam, precioUnitarioAA, diferencia, km);
				}
				else
				{
					printf("Atencion. Primero se necesitan hacer los calculos de los precios en la opcion 3. \n");
				}
			break;
			case 5:
				precioDebitoLatam = pagoConDebito(159339);
				precioDebitoAA = pagoConDebito(162965);
				precioCreditoLatam = pagoConCredito(159339);
				precioCreditoAA = pagoConCredito(162965);
				precioBtcLatam = pagoConBtc(159339);
				precioBtcAA = pagoConBtc(162965);
				precioUnitarioLatam = precioXKm(159339, 7090);
				precioUnitarioAA = precioXKm(162965, 7090);
				diferencia = 159339 - 162965;
				informeDeResultados(159339, 162965, precioDebitoLatam, precioDebitoAA, precioCreditoLatam, precioCreditoAA, precioBtcLatam, precioBtcAA, precioUnitarioLatam, precioUnitarioAA, diferencia, 7090);
			break;
			case 6:
				salir = 's';
			break;
			case 7:
				informarNoEsNumero();
				break;
			default:
				printf("Opcion invalida. Ingrese un numero de la lista: \n");
		}
		fflush(stdin);
		system("pause");
	  }while(salir != 's');

	printf("Hasta pronto!");
	return 0;
}

