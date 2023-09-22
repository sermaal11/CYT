/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:49:54 by sergio            #+#    #+#             */
/*   Updated: 2023/09/22 10:50:10 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Un bucle es una region de codigo que se va a ejecutar multiples veces. Este bucle
// se ejecutará mientras una determinada condicion se cumpla.
// Nosotros debemos declarar la rutina con la que queremos que se repita y luego 
// establecer la condicion por la que queremos que se salga del bucle.
//
// En C encontramos 3 tipos de bucles. Tenemos el while, el do-while y el for.
//


int main(void)
{
	// While:
	//
	// La sintaxis de este bucle seria la siguiente:
	//
	// while (condicion)
	// {
	// 	*codigo*
	// }
	//
	// Lo que va a hacer C cuando se encuentra un while va a ser evaluar la condicion
	// y si esa condicion se cumple, va a ejecutar el codigo que se encuentra entre los
	// corchetes.
	// Una vez que ha terminado de ejecutar el codigo, va a volver a la condición que 
	// hemos puesto al principio y la va a evaluar de nuevo hasta que se deje 
	// de cumplir. Una vez que se deje de cumplir, C se saldra del while y continuara
	// ejecutando codigo donde lo ha dejado.
	//
	// Para evitar que haya bucles infinitos, es necesario que la condicion tenga
	// una forma de romperse. En este ejmplo, mediante k++, creamos un operador
	// postincremental que hara incremental el valor de k en 1 cada vez que se ejecuta
	//
	// Ejemplo:
	//

	int k;

	k = 10;
	printf("While ejecuta el codigo entre 0 y N veces\n");
	printf("\n");
	printf("Ejemplo while\n");
	while (k < 20)
	{
		printf("k vale %d\n", k);
		k++;
	}
	printf("hemos salido del bucle.\n");
	printf("\n");
	
	k = 20;
	printf("Inicio while\n");
	while (k < 20)
	{
		printf("Iteracion.\n");
	}
	printf("Fin while.\n");
	printf("\n");

	// Do-While:
	// 
	// La sintaxis de este bucle es la siguiente:
	//
	// do
	// {
	//	*codigo*
	// }
	// while (condicion);
	//
	// La diferencia entre while y do-while es que el do-while evalua la condicion 
	// despues de ejecutar el codigo. Eso significa que primero va a ejecutar codigo
	// y despues va a evaluar si puede volver a ejecutarlo. En el momento en el que 
	// la condicion no se cumpla, continuara ejecutando el codigo donde se quedo y
	// no volvera hace los corchetes superiores del do.
	//
	// La diferencia principal entre while y do-while es que while va a ejecutar el
	// codigo 0 o mas veces, y do-while va a ejecutar el codigo 1 o mas veces.
	//
	// Ejemplo:
	//
	
	k = 10;
	
	printf("Do-while realiza bucle entre 1 y N veces\n");
	printf("\n");
	printf("Ejemplo do-while\n");
	do
	{
		printf("k vale %d\n", k);
		k++;
	}
	while (k < 20);
	printf("hemos salido del bucle.\n");
	printf("\n");

	k = 20;
	printf("Inicio do-while.\n");
	do
	{
		printf("Iteracion.\n");
	}
	while (k < 20);
	printf("Fin do-while.\n");
	printf("\n");

	// For:
	//
	// La sintaxis de este bucle es la siguiente
	//
	// for (inicializacion; condicion; iteracion)
	// {
	//	*codigo*
	// }
	//
	// El for lo utilizamos cuando queremos una condicion se ejecute un numero 
	// determinado de veces.
	// La explicacion de la sintaxis seria la siguiente. En inicializacion escribimos
	// las variables que se van a inicializar en el momento de ejecutar el bucle for y
	// que se va a ejecutar una unica vez. Si escribimos la variable de la siguiente
	// manera:
	//
	// int i = 0; Esta variable solo va a existir dentro del bucle for, por lo que una
	// vez que abandonemos el bucle, esta variable va a dejar de existir y ya no vamos
	// a poder volver referirnos a ella. El problema de esto es que en modo ANSII, esto 
	// no va a compilar, por lo que deberemos compilar mediante gcc -std=99.
	// Para evitar esto escribiramos la variable i como se indica en el ejemplo.
	//
	// En condicion escribirimos la condicion que usaremos para ejecutar el bucle, 
	// es decir, mientras esa condicion se cumpla, el bucle se continuara repitiendo.
	// En nuestro ejemplo, como queremos que el bucle se repita 5 veces, nuestra condicion
	// será i < 5.
	//
	// En iteracion escribiremos el codigo que se va a ajecutar cada vez que se complete
	// una iteración de bucle. En el ejemplo, nuestro codigo va a ser un incremental de i
	// porque queremos que i aumente en 1 su valor despues de cada iteración. De esta 
	// manera, podemos llevar un registro de cuantas veces se ha ejecutado.
	//
	// Finalmente, entre corchetes, escribiremos el codigo del bucle.
	// El ciclo de vida de este bucle por tanto seria el siguiente:
	//
	// 1: Ejecutar la "inicializacion".
	// 2: Evaluar condicion. Si no se cumple, fin del bucle.
	// 3: Ejecutar el codigo del bucle.
	// 4: Ejecutar la iteración.
	// 5: volver al paso 2.
	//
	
	int i;
	printf("Inicio bucle for.\n");
	for (i = 0; i < 5; i++)
	{
		printf("Ahora estoy en la iteración %d.\n", i);
	}
	printf("Hemos salido del bucle for.\n");
	printf("Fin bucle for.\n");

	return (0);
}

















