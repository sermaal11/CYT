/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_estaticas_locales.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:11:33 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/22 22:41:55 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La principal diferencia entre una variable estática y una variable no
// estática (también conocida como variable automática) radica en su duración 
// y ámbito de vida.

// Varible automatica:
//
// Duración:				Una variable no estática se crea y se destruye cada vez que
// la función en la que está definida se llama o sale de su ámbito. Su valor se
// reinicia cada vez que se entra en la función.
//
// Ámbito de vida:	El ámbito de vida de una variable no estática se limita a
// la función en la que está definida. La variable no es visible fuera de la
// función.
//
// Ejemplo:					Una variable que se utiliza para almacenar datos temporales
// o cálculos dentro de una función, pero cuyo valor no necesita persistir
// entre llamadas a la función.

#include <stdio.h>

void contador_no_estatico(void)
{
	int	non_static_count;

	non_static_count = 0;
	non_static_count++;
	printf("Variable no estática (automática): %d\n", non_static_count);
}

// Variable estatica:
//
// Duración:				Una variable estática mantiene su valor a lo largo de la
// ejecución del programa. Es decir, se inicializa una sola vez y su valor
// persiste entre llamadas a la función en la que está definida o a lo largo de
// toda la ejecución del programa si es una variable estática global.
//
// Ámbito de vida:	El ámbito de vida de una variable estática local se limita
// a la función en la que está definida, y su valor se mantiene entre llamadas
// a esa función. El ámbito de vida de una variable estática global se limita
// al archivo fuente en el que está definida, lo que significa que no es
// visible ni accesible desde otros archivos fuente.
// Ejemplo:					Un contador que acumula un valor entre llamadas sucesivas
// a una función.

void contador_estatico(void)
{
	static int	static_count;

	static_count++;
	printf("Variable estática: %d\n", static_count);
}

int	main(void)
{
	printf("Llamadas a la función contador con variable no estática:\n");
  contador_no_estatico();  // Llamada 1
  contador_no_estatico();  // Llamada 2
  contador_no_estatico();  // Llamada 3
	printf("Llamadas a la función contador con variable estática:\n");
  contador_estatico();  // Llamada 1
 	contador_estatico();  // Llamada 2
 	contador_estatico();  // Llamada 3
	
	return (0);
}


