/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   punteros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:54:15 by sergio            #+#    #+#             */
/*   Updated: 2023/09/22 12:36:32 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//	La memoria de un ordenador esta distribuida como si de un gran casillero se
//	tratase. Cada dato se encuentra almacenado en una de las casillas, en la
//	que cada una se encuentra identificada con una direccion de memoria.
//
//	Para poder manipular esas direcciones, tenemos un tipo de dato llamado 
//	puntero. Este tipo de dato, nos permite guardar direcciones de memoria.
//
//	Mediante un puntero, podemos recuperar y modificar la informacion contenida 
//	en una celda de memoria, sin importar a que variable este asignada.
//	
//	Es importante cuando trabajmos con punteros, asegurarnos de escribir en
//	celdas de memoria disponibles y que estan reservadas para nosotros.
//
//	El principal uso que le vamos a dar a los punteros va a ser para trabajar con
//	referencias en funciones.
//

void ft_example(int n)
{
	n = (n + 3) * 2 - 1;
	printf("%d\n", n);
}

void ft_example_ptr(int *n)
{
	// Modificamos la funcion para que en vez de un entero le pasemos un puntero
	// a un numero entero, es decir, la poscion de memoria donde se almacena
	// ese numero entero.
	//
	// Mediante la siguiente construccion "rescato" lo que hay en esa posicion de
	// memoria.
	//
	int y;
	// Mediante el * recupero el valor que se almacena en ese puntero.
	y = *n;

	y = y + 2;
	printf("%d\n", y);
	*n = y;
}

int	main(void)
{	
	int	x;
	x = 10;
	
	// Cuando nostros pasamos una variable como argumento de una funcion, lo que
	// en verdad le estamos pasando es una copia de esa variable y cuando se termina
	// de ejcutar una funcion, esa copia de la variable muere y regresa a su valor
	// original.
	
	printf("La funcion ft_example utiliza el valor 10 de la variable x\n");
	printf("La funcion ft_example devuelve el valor n despues de operar con x\n");
	ft_example(x);
	printf("La copia de la variable x muere");
	
	printf("la variable x recupera su valor original\n");
	printf("x = %d\n", x);
	
	printf("La funcion ft_example_ptr utiliza el valor 10 de la variable x \n");
	printf("La funcion ft_example_ptr devuelve el valor n despues de operar con x\n");
	ft_example_ptr(&x);
	printf("La funcion ft_example_ptr guarda en la direccion de memoria en el que estaba x el valor de y\n");
	printf("La variable x ahora vale:\n"); 
	printf("x = %d\n");
	

	// Mediante la construccion &(variable) devolvemos la direccion de memoria en
	// la que se encuentra nuestra variable.

	printf("Direccion de memoria de la variable x\n");
	printf("x = %u\n", &x);

	// Para guardar una direccion de memoria utilizamos un tipo de dato especial.
	// Este tipo de dato es el denominado puntero y lo declaramos de la 
	// siguiente manera:

	// Mediante la construccion anterior, estoy obteniendo una direccion de
	// memoria (&x) y la estoy guardando en otra direccion de memoria (*dirx).
	// Un puntero funciona como cualquier otro tipo de variable.
	//
	
	return (0);
 }
