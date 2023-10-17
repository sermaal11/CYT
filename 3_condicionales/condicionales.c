/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condicionales.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:24:44 by sergio            #+#    #+#             */
/*   Updated: 2023/10/04 12:01:49 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CONDICIONALES:
//
// En el caso de C vamos a encotrar 2 tipos de condicionales. Uno seria el 
// if-else y otro seria el switch.
//
// Lo que hacen estos condicionales es que en funcion de una determinada 
// condicion, se jecute un bloque de codigo u otro.
//
// La sintaxis del if seria la siguiente:
//
// if ( condicion )
// {
//		Si la cndicion es true, ejecuta este bloque de codgo
// }
// else
// {
//		Si la condicion es false, ejecua este bloque de codigo.
// }
//
// Para expresar nuestras condicones tenemos una serie de operadores logicos, 
// los cuales serian los siguientes:
//
//  - ==: Igual a.
//  - !=:	Distinto a.
//  - >:	Mayor que.
//  - >=:	Mayor o igual que.
//  - <:	Menor que.
//  - <=: Menor o igual que.
//
//  Ademas, tenemos los operadores que nos permiten evaluar mas de una 
//  condicion. Estos operadores serian los siguientes:
//
//  - &&: operador and.
//  - ||: Operador or.
//
//  Los operadores logicos, ademas, podemos agruparlos entre parentesis 
//  para que se evaluen como uno solo, por ejemplo:
//
//  if ((num1 > 3 && num1 < 5) || num1 == 7)
//
//  En este caso, nuestra condicion se cumplira si num1 esta entre 3 y 5 o 
//  es igual a 7 
//
//  Todo lo que esta fuera del if se ejecutara siempre.

#include <stdio.h>
#include <unistd.h>

void if_else_conditional(int num)
{
	if (num >= 0 && num < 10)
	{
		write(1, "P\n", 2);
	}
	else if (num < 0 && num > -10)
	{
		write (1, "N\n", 2);
	}
	else if (num <= -10 || num >= 10)
	{
		printf("Fuera de rango\n");
	}

	printf("Esto se ejcuta siempre porque esta fuera del if-else\n");
}

// C tiene un segundo tipo de condicional que es el switch. Switch lo 
// utilizamos cuando tenemos un monton de posibles valores y queremos que 
// se ejecute un codigo en funcion de lo que valga. Mediante el uso del switch,
// solo escribiremos el nombre de la variable una sola vez.
//
// Mediante la palabra clave case, le indico el caso a evaluar. 
//
// La sintaxis seria la siguiente:
//
// switch (nombre de la variable a evaluar)
// {
//		case valor variable a evaluar:
//			accion a llevar a cabo si evaluo como true;
//			break;
//		case ...:
//			accion ...;
//			break;
//			.
//			.
//			.
//		default:	
// }
//
// Si no se cumple ninguna condicion de las que hemos indicado en case, 
// usaremos la palabra clave default.
//
// La palabra break es una palabra clave que usamos para decirle a C que salga
// de la condicion. Si no ponemos la palabra break, se va aejecutar todo el 
// codigo que este por debajo.

void switch_print_day(int numday)
{
	switch(numday)
	{
		case 1:
			printf("Lunes\n");
			break;
		case 2:
			printf("Martes\n");
			break;
		case 3:
			printf("Miercoles\n");
			break;
		case 4:
			printf("Jueves\n");
			break;
		case 5:
			printf("Viernes\n");
			break;
		case 6:
			printf("Sabado\n");
			break;
		case 7:
			printf("Domingo\n");
			break;
		default:
			printf("Fuera de rango\n");
			break;
	}

	printf("Esto se ejecuta siempre porque esta fuera del switch\n");
}

int main(void)
{
	if_else_conditional(9);
	switch_print_day(7);
	return (0);
}
