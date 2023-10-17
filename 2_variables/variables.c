/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:36:05 by sergio            #+#    #+#             */
/*   Updated: 2023/10/04 11:59:32 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ASIGNACION: Cuando trabajamos con la memoria manipulando valores. La memoria
// es el recurso que tiene el ordenador llamada memoria RAM, que usa para
// guardar datos temporalmente. Los datos guardados en la memoria RAM
// desaparecen en cuanto el programa termina. La memoria es el recurso mas
// manejable de nuestro programa.
//
// MEMORIA:		 La memoria no son mas que celdas a las que podemos acceder y 
// manipular  su valor. Es por eso que necesitamos una forma de identificar 
// correctamente a esas celdas y de decirle al programa de que forma vamos a 
// utilizar esa	celda. Es ahi donde surgen las variables y los identificadores.
//
// VARIABLES:	 Cuando declaramos una variable, lo que hacemos es decirle a C 
// que nos guarde un trocito de memoria para utilizarla de detemrinada forma, 
// como por ejemplo para guardar un numero (int, float), para guardar un caracter
// (char)...
//
// Una vez que tenemos definida la variable y el identificador declarado, 
// nostros podemos guardar un valor en esa celda de memoria y despues 
// recuperarlo. Cuando recuperamos un valor, podemos utilizarlo de la forma
// que mas nos convenga.
//
// Para declarar una variable, lo primero que tenemos que hacer es decir
// que tipo de dato que queremos utilizar con esa variable y seguidamente el 
// identificador que le quiero asignar. Cada identificador ha de ser unico
// y descriptivo. No podemos usar identificadores que ya se este usando en 
// otras funciones.
//
// TIPOS DE INT: Cada uno va a tener un tamaño de bits para guardar valores, 
// de forma que cuantos mas bits tenga, va a poder guardar valores mayores.
// 
// 		- short: Variable de 16 bits. Puede guardar numeros del -32768 al 32767
// 		- int:	 Variable de 32 bits. Puede guardar numeros del 
//				2147483648 al 2147483647
// 		- long:	 Variable de 64 bits. Puede guardar numeros del -2^63 al 2^63
//
// Si queremos guardar las variables sin signo, podemos usar el prefijo unsigned, 
// quedando la expresion de la siguiente manera: unisgned int. Al no utilizar 
// signo, utiliza todos los bits para guardar numeros positivos, por lo que los 
// valores se modifican:
//
// 		- unsigned short: Guardara numeros del 0 al 65535.
//		- unsigned int:	 Guardara numeros del 0 al 4294967295.
//		- unsigned long:	 Guardara nuneros del 0 al (2^64) - 1.
//
 
#include <stdio.h>

void print_data(int age, char* name)
{
	printf("Tu nombre es %s y tu edad es de %d años.", name, age);
}

int main(void)
{
	/* 
	Lo que hemos puesto a continuacion seria la declracion de la variable, y 
	lo que hemos hecho en este caso ha sido resrvar memoria para guardar 
	un caracter y para guardar un numero entero.
	*/

	char	lett;		// Variable tipo char con el identificador lett.
	int		nbr;		// Variable tipo int con el identificador nbr.
	
	/*
	Para asignar valores a nuestras variables, hariamos lo siguiente. 
	Escribiriamos el nombre o identificador de nuestra variable, y a 
	continuacion, le asignaramos el valor que deseasemos que almacenase.

	Nuestra variable tipo char con el identificador lett, contrendra el 
	caracter 'a', mientras que nuestra variable tipo int con el identificadro 
	nbr, contrendra el numero entero 33
	*/
	
	lett = 'a'; 
	nbr = 33;

	/*
	Podemos declarar variables que tomen valores de otras variables, como por 
	ejemlo, si quisiesemos una variable que es el doble de nuestra variable nbr,
   	podriamos hacer lo	siguiente:
	*/

	int nbrdoub;
	nbrdoub = nbr * 2; 
	
	/*
	En la linea superior decimos que nbrdoub es una variable de tipo entero 
	que valdra el doble que nbr mediante la operacion matematica de 2 * nbr. 
	Por lo que si nbr vale 33, nbrdoub valdra 66.
	*/
	
	/*
	Para poder ver los valores de las variables por pantalla, vamos a ayudarnos 
	de la funcion printf.
	Para que printf nos imprima el valor de una variable usamos un placeholder.
	para usar en placeholder con printf, lo indicamos con el simbolo % y a 
	continuacion ponemos un caracter que indicara el tipo de la variable que 
	queremosque escriba.
	Los caracters que podemos usar son los siguientes:
	
	- %c: caracter
	- %d: decimal
	- %i: int
	- %f: float
	- %s: string o cadena de caracteres
	- %u: unsigned int
	- %p: direccion de puntero

	Mediante el simbolo \n indicamos que queremos un salto de linea.

	Una vez le hemos indicado cual es el placeholder que usamos, hay que 
	escribirle el identificador de la variable que queremos escribir, 
	quedando la sintaxis de la siguiente manera:

	- printf("Texto %placeholder", id variable);

	Si queremos mostras varias variables con un printf, la sintaxia quedaria 
	de la siguiete manera:

	- printf("Texto %placeholder %placeholder %", id variable, id variable);
	*/

	printf("El valor de nbr es: %i\n", nbr);
	printf("El valor de nbrdoub es: %i\n", nbrdoub);
	printf("El valor de lett es: %c\n", lett);
	printf("Los valores de las variables son: %d, %d, %c\n", nbr, nbrdoub, lett);
	print_data(32, "sergio"); 
	return (0);
}
