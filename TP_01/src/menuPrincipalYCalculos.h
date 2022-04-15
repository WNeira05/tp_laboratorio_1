/*
 * menuPrincipalYCalculos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: W. Neira
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */

/// @brief Muestra las opciones del menu principal
///
/// @return retorna la opcion del menu elegida
int menuPrincipal();

/// @brief Informa los resultados segun la opcion de pago elegida.
void informeDeResultados(float, float, float, float, float, float, float, float,
		float, float, float, float);

/// @brief Imprime el mensaje informando que la opcion elegida no es del tipo int
void informarNoEsNumero();

/// @brief Ingresa los Kms del vuelo
///
/// @return retorna el valor ingresado por el usuario.
float ingresoDeKm();
/// @brief
///
/// @param
/// @return
float ingresoDePrecio(int);

/// @brief Calcula el valor con el 10% de descuento.
///
/// @param valor al que hay que calcularle el descuento
/// @return retorna el valor final con ese descuento realizado.
float pagoConDebito(float);

/// @brief Calcula el valor con el 25% de aumento.
///
/// @param valor al que hay que calcularle el aumento
/// @return retorna el valor final con el aumento realizado
float pagoConCredito(float);

/// @brief calcular el valor en bitcoins
///
/// @param valor a calcular en Bitcoins
/// @return retorna el valor final en Bitcoins
float pagoConBtc(float);

/// @brief Calcular el precio por Km
///
/// @param Precio
/// @param Kms totales
/// @return retorna el valor del precion x km
float precioXKm(float, float);
/// @brief Guarda los valores de los precios de cada aerolinea
///
/// @param mensaje para ingreso de precio
/// @param mensaje de error por valor ingresado incorrecto
/// @return el precio del vuelo
int ingresoPrecioVuelos(char*, char*);
